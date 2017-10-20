#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


/*

message pair structure
	uint32 size
	char * message
	
file spec:	
	char * Header = CS2060 with no null byte
	uint32 keylocation
	messagePair First Name
	messagePair Last Name
	messagePair Message 1 = what grade you think you should get in class
	messagePair key
	messagePair message 2 = go for lol points
	
	No code needed for assignment, just send the output file (.dat or .bin is an appropriate file name extension)

*/
int xor(char * in, uint32_t insize, char * pass, uint32_t passSize){
	uint32_t i;
	for(i = 0; i < insize; i++){
		in[i] = in[i]^pass[i%passSize];
	}
	return i;
}


int main(int argc, char ** argv){

	if(argc != 2){
		fprintf(stderr,"Usage: %s [filename]\n",argv[0]);
		return 1;
	}
	FILE * fh = fopen(argv[1],"rb");
	if(!(fh)){
		fprintf(stderr,"Could not open file\n");
		return 1;
	}
	
	char header[7];
	uint32_t keyloc;
	uint32_t fsize;
	uint32_t lsize;
	uint32_t keysize;
	uint32_t m1size;
	uint32_t m2size;
	uint32_t realLocation;
	
	char * first;
	char * last;
	char * key;
	char * m1;
	char * m2;
	
	fread(header, 6, 1, fh);
	
	if(strncmp(header,"CS2060",6)){
		fprintf(stderr,"header is incorrect\n");
		return 2;
	}
	

	fread(&keyloc,sizeof(uint32_t),1,fh);
	
	fread(&fsize,sizeof(uint32_t),1,fh);
	first = (char *)malloc(fsize+1);
	fread(first,fsize,1,fh);
	first[fsize] = '\0';
	
	fread(&lsize,sizeof(uint32_t),1,fh);
	last = (char *)malloc(lsize+1);
	fread(last,lsize,1,fh);
	last[lsize] = '\0';
	
	fread(&m1size,sizeof(uint32_t),1,fh);
	m1 = (char *)malloc(m1size+1);
	fread(m1,m1size,1,fh);
	m1[m1size] = '\0';
	
	realLocation = ftell(fh);
	fread(&keysize,sizeof(uint32_t),1,fh);
	key = (char *)malloc(keysize+1);
	fread(key,keysize,1,fh);
	key[keysize] = '\0';
	
	fread(&m2size,sizeof(uint32_t),1,fh);
	m2 = (char *)malloc(m2size+1);
	fread(m2,m2size,1,fh);
	m2[m2size] = '\0';
	xor(m2,m2size,key,keysize);
	
	printf("First: %s\n",first);
	printf("Last: %s\n",last);
	printf("m1: %s\n",m1);
	printf("m2: %s\n",m2);
	
	if(realLocation == keyloc){
		printf("The location is correct\n");
	}else{
		printf("The location is INCORRECT\n");
	}
	
	
	
	
	
	
	


	return 0;
}

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int xor(char * in, uint32_t insize, char * pass, uint32_t passSize){
	uint32_t i;
	for (i = 0; i < insize; i++){
		//what does ^ do?
		in[i] = in[i]^pass[i%passSize];
	}
	return i;
}

int main() {
	FILE * fh = fopen("outfile.dat","rb");
	if (!(fh)){
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
	uint32_t reallocation;
	
	char * first;
	char * last;
	char * key;
	char * m1;
	char * m2;
	
	//read header, always 6
	fread(header, 6, 1, fh);
	if (strncmp(header, "CS2060", 6)){
		fprintf(stderr, "header is incorrect\n");
		return 2;
	}
	
	//read key location
	fread(&keyloc,sizeof(uint32_t),1,fh);

	//read fn size
	fread(&fsize,sizeof(uint32_t),1,fh);
	//	read in fn
	first = (char *)malloc(fsize + 1);
	fread(first,fsize,1,fh);
	first[fsize] = '\0';
	
	//read in ln size
	fread(&lsize,sizeof(uint32_t),1,fh);
	//	read in ln
	last = (char *)malloc(lsize + 1);
	fread(last,lsize,1,fh);
	first[lsize] = '\0';
	
	//read m1 size
	fread(&m1size,sizeof(uint32_t),1,fh);
	//	read in m1
	m1 = (char *)malloc(m1size + 1);
	fread(m1,m1size,1,fh);
	m1[m1size] = '\0';
	//errors here? 
	/*
	reallocation = ftell(fh);
	fread(&keysize, sizeof(uint32_t,1,fh));
	key = (char * )malloc(keysize + 1);
	fread(key,keysize,1,fh);
	key[keysize] = '\0';
	*/
	
	//read m2 size
	fread(&m2size,sizeof(uint32_t),1,fh);
	//	read in m1
	m2 = (char *)malloc(m2size + 1);
	fread(m2,m2size,1,fh);
	m2[m2size] = '\0';
	
	xor(m2, m2size, key, keysize);
	
	printf("First: %s", first);
	printf("last: %s", last);
	printf("m1: %s", m1);
	//m2 encrypted
	//xor encrypted with 42 last week in lecture
	//printf("m2: %s", m2);
		
	return 0;
}


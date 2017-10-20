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


int main(){

	uint32_t realLocation;

	char string1[] = "CS2060";
	uint32_t keyloc;
	char first[] = "Rodger";
	uint32_t fsize = sizeof(first);
	char last[] = "Byrd";
	uint32_t lsize = sizeof(last);

	char m1[] ="I'm getting an A in this class";
	uint32_t m1size = sizeof(m1);

	/*
	char string1[] = "This is a string";
	uint32_t inString1Size = sizeof(string1);
	xor(string1, inString1Size);
	*/
	
	char key[] = "badkey";
	uint32_t keysize = sizeof(key);
	

	
	char m2[] = "After working for years, a hooker finally retired and, being afraid of spending the rest of her life alone, she decided to marry.\n\nShe had been with so many perverted men over the years that she felt she needed a change, and would only get one by marrying a virgin male near her age. She took out ads in newspapers around the world seeking a male virgin who was 55 years old. She finally narrowed her choice to an Australian computer programmer. After a thorough background check, she was satisfied that he had indeed never been with a woman and they were married.\n\nOn their wedding night, she went into the bathroom to change into her nightie. When she came back out, she found that her new husband had taken the bed and everything in the room and stacked it in one corner of the room. Thinking this was rather kinky, she said to her husband, 'I thought you had never been with a woman.' He replied, 'That's true, but if it's anything like screwing a kangaroo, we're going to need all the room we can get!";

	uint32_t m2size = sizeof(m2);
	//uint32_t inString1Size = sizeof(string1);
	
	FILE * fh;
	fh = fopen("rodgerbyrd.dat","wb"); 
	//always check opened
	if (!(fh)){ 
		fprintf(stderr, "File %s did not open", "rodgerbyrd.dat");
		return 1;
	}
	
	//write CS2060
	fwrite(&string1,6,1,fh);
	
	//write keyloc
	keyloc = 0;
	fwrite(&keyloc,sizeof(uint32_t),1,fh);
	
	//write first
	fwrite(&fsize,sizeof(uint32_t),1,fh);
	fwrite(&first,fsize,1,fh);
	
	//write last
	fwrite(&lsize,sizeof(uint32_t),1,fh);
	fwrite(&last,lsize,1,fh);
	
	//write m1
	fwrite(&m1size,sizeof(uint32_t),1,fh);
	fwrite(&m1,m1size,1,fh);	
	
	//write key
	realLocation = ftell(fh);
	fwrite(&keysize,sizeof(uint32_t),1,fh);
	fwrite(&key,keysize,1,fh);
		
	//write m2
	xor(m2, m2size, key,keysize);
	fwrite(&m2size,sizeof(uint32_t),1,fh);
	fwrite(&m2,m2size,1,fh);	

	
	
	//count file size
	//rewind file size
	//write address of key
	//fseek(fh,6,SEEK_SET);	
	fseek(fh,6,SEEK_SET);	
	fwrite(&realLocation,sizeof(uint32_t),1,fh);
	
	
	fclose(fh);
	return 0;
}

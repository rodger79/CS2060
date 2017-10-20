#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int xor(char * instring, uint32_t insize){
	for (uint32_t i = 0;i<insize;i++){
		instring[i] = instring[i] ^ 42;
	}
	return 0;
}

int main(){

	FILE * fh;
	
	//"w' is destructive open, "aw" is append write, "wb"  binary mode
	fh = fopen("testfile.txt","wb"); 
	//always check opened
	if (!(fh)){ 
		fprintf(stderr, "File %s did not open", "testfile.txt");
		return 1;
	}

	char string1[] = "This is a string";
	uint32_t inString1Size = sizeof(string1);
	xor(string1, inString1Size);
	
	uint32_t num1 = 42;
	uint64_t num2 = 24;
	uint32_t stringSize = strlen(string1)+1;
	
	
	//input, size, count, filehandle
	fwrite(&num1,sizeof(uint32_t),1,fh);
	fwrite(&num2,sizeof(uint64_t),1,fh);
	fwrite(&stringSize,sizeof(uint32_t),1,fh);
	fwrite(&string1,inString1Size,1,fh);
	
	//non binary mode
	//fprintf(fh,"%s %d %ld\n", string1, num1, num2);
	
	fclose(fh);
	fh = fopen("testfile.txt","rb"); 
		//always check opened
	if (!(fh)){ 
		fprintf(stderr, "File %s did not open", "testfile.txt");
		return 1;
	}
	
	uint32_t inNum1 = 0;
	uint64_t inNum2 = 0;
	uint32_t inStringSize = 0;
	char buffer[1024];
	
	fread(&inNum1,4,1,fh);
	fread(&inNum2,8,1,fh);
	fread(&inStringSize,4,1,fh);
	fread(buffer,inStringSize,1,fh);
	xor(buffer,inStringSize);
	
	printf(" %d %ld %d %s\n", inNum1, inNum2, inStringSize,buffer);
	
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc, char **argv){
	
	if (argc != 3){
		printf("Usage %s: [number]\n",argv[0]);
		return 1;	
	} else if (!(strcmp(argv[1],  "-j"))){
		printf("Usage %s: [number]\n",argv[0]);
		return 1;	
		
		int value = atoi(argv[2]);
		value = value*value*value;
		printf("%d\n",value);
			return 1;	
	} else if (!(strcmp(argv[1],  "-c"))){
		int value = atoi(argv[2]);
		value = value*value*value;
		printf("%d\n",value);
		
	}
	char * first = "this is the first string\n";
	char * second = "this is the second\n";
	char * third = "this is the third\n";
	
	char * strArray[3];
	char** arrayPtr = strArray;
	strArray[0] = first;
	strArray[1] = second;
	strArray[2] = third;
	
/* 	printf("%s",*arrayPtr++);
	printf("%s",*arrayPtr++);
	printf("%s",*arrayPtr); */
	
	
	
	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	int lines = 2;
	for (int i = lines; i >=0; i--){
		printf("%s",strArray[i]);
	}
/* 	int value = argv[1] *argv[1] * argv[1]; //can't multiply strings aka char *
	printf("%d\n", value); */

	
	
/* 	char * strPtr;
	strPtr = first; //actual val unk mem location
	printf("%c\n",*strPtr++);
	printf("%c\n",*strPtr++);
	printf("%c\n",*strPtr++);
	printf("%c\n",*strPtr++);
	printf("%c\n",*strPtr++);
	printf("%c\n",*strPtr++);
	printf("%c\n",*strPtr++);
	printf("%s\n",strPtr++); */
	
	return 0;
}
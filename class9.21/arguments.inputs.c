#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getAline(char ** inputAddress){

	char * string1;
	
	
	int stringSize = 10;
	
	string1 = (char*) malloc(stringSize);
	
	
	int index = 0;
	while( (string1[index] = getchar()) != '\n' && (string1[index] != EOF) ){
		index++;
		if (index >= stringSize ){
			stringSize *=4;
			char * temp = (char*) malloc(stringSize);
			for (int i = 0; i < index; i++){
				temp[i] = string1[i];
			}
		free(string1);
		string1 = temp;
		}
	}
	
	string1[index] = '\0';
	
	*inputAddress  = string1;
}


int main(int argc, char ** argv){

 if (argc != 2) {
	 fprintf(stderr, "%s: takes exactly one argument\n", argv[0]);
	 return 1;
 }
 
 if( (strcmp("-s",argv[1])) ){
	 fprintf(stderr, "%s:, you must supply an option [-s]\n",argv[0]);
	 return 1;
 }
	char * stringInput[4];
	
	getAline(&(stringInput[0]));
	getAline(&(stringInput[1]));
	getAline(&(stringInput[2]));
	getAline(&(stringInput[3]));
	printf("%s\n",stringInput[0]);
	printf("%s\n",stringInput[1]);
	printf("%s\n",stringInput[2]);
	printf("%s\n",stringInput[3]);
	
	printf("%s\n",stringInput[3]);
	printf("%s\n",stringInput[2]);
	printf("%s\n",stringInput[1]);
	printf("%s\n",stringInput[0]);
	
return 0;	

}

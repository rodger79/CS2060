//Filename:			HW3RodgerByrd.c
//Student Name:		Rodger Byrd
//Date:				10-01-15
//Purpose:			reverse lines or reverse words
//How to use:		Call with the Switch -W or -L to format the input lines

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declarations
size_t getAline(char **);
void printForward(char *);

//Function: main
//Prototype with arg Types: takes one argument, switch
//How to use: Runs automatically
//What it does: takes input and reformats it to stdout
int main(int argc, char * argv[]){

	//check for the correct arguments
	if (argc!= 2){
		fprintf(stderr, "%s: takes exactly one argument\n", argv[0]);
		return 1;	
	}
	if (!(strcmp (argv[1], "-L"))){
		;
	} else if (!(strcmp (argv[1], "-W"))){
		;
	} else {
		 fprintf(stderr, "%s:, you must supply an option [-L] or [-W]\n",argv[0]);
		 return 1;	
	}
	
	
	//Define variables
	char * buffer; //memory address
	char * array[1024];
	size_t index = 0;
	size_t bytes_read = 0; //generic type syze_t

	//get input
	//& reference operator, send address of buffer which is itself a  memory address
	while ((bytes_read = getAline(&buffer)) !=0){
		array[index++] = buffer;
	}
	

	if (!(strcmp (argv[1], "-L"))){
		for (int i = index -1; i >=0; i--){
			printf("%s", array[i]);
		}
	} else if (!(strcmp (argv[1], "-W"))){
		
		for (int i = 0; i <index; i++){
			char * input = array [i];
			int rcount = 0;
			int length = strlen(input);
			//for testing
			//printf("%s\n",input);
			//cycle through each char in the string to locate spaces
			for (int j = (length-1); j >=0; j--){
				rcount++;
				if ( input [j] == ' ' ){
					//when finding a space, print line from the
					//point of the space on
					printForward((char*)(input + length- rcount+1));
					//add space back in after
					printf(" ");
					//replace space with null
					input[j] = '\0';
				} else if ( j == 0 ){
					//add first word back in
					printForward(input);
				}
			}
			puts("");
		}		
	}
return 0;
}
//Function: getAline
//Prototype with arg Types: takes one argument, a char ** or string array
//How to use: called from main to get input
//What it does: reads in lines from stdin and stores them
size_t getAline(char ** bufferPtr){

	char * buffer = *bufferPtr; //declaration 
	size_t arraySize = 10;
	buffer = (char *)malloc(arraySize * sizeof(char));
	size_t index = 0;
	
	while((buffer[index] = getchar()) != EOF && (buffer[index++] != '\n')){ 
		//quits if EOF without incrementing index
		if(index >= arraySize){
			arraySize *= 4;
			char * temp = (char *)malloc (arraySize* sizeof(char));
			for (int i = 0; i < index; i++){
				temp[i] = buffer[i];
			}
			free(buffer);
			buffer = temp; //change pointer value of buffer to pointer value of temp
		}
	}
	
	buffer[index] = '\0';
	*bufferPtr = buffer; //malloc overwrites memory address, need to write new address
	return index;
}

//Function: printForward
//Prototype with arg Types: takes one argument, a char * or char array
//How to use: called from main to prints a string to stdout
//What it does: prints to stdout
void printForward(char * buffer){

	int len = strlen(buffer);
	//reverse index for backwards
	for (int i = 0; i<len; i++){
		//strlen is index of last char (no null)
		if ( buffer[i] == '\n') {
			//do nothing
		} else {
			putchar(buffer[i]);
		}
	}

}

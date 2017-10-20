//Filename:			ReadARevIIRodgerByrd.c
//Student Name:		Rodger Byrd
//Date:				11-11-15
//Purpose:			reverse lines, reverse words or alphabetize
//How to use:		Call with the Switch -W or -L or -A to format the input lines

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	char * val;
	struct node * next;
	
} Node;

//declarations
size_t getAline(char **);
void printForward(char *);
int insert(Node **, char *);
int alphaLess(char * , char *);
int printList(struct node * );

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
	} else if (!(strcmp (argv[1], "-A"))){
		;
	} else {
		 fprintf(stderr, "%s:, you must supply an option [-L], [A] or [-W]\n",argv[0]);
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
	} else if (!(strcmp (argv[1], "-A"))){
		Node * root = NULL;
		for (int i = 0; i < index; i++){
			insert(&root,array[i]);
		}
		//print root
		printList(root);
	}
return 0;
}

int insert(Node ** rootPtr, char * buffer){
	Node * current;
	
	if(!(rootPtr)){
		return 0; //check for bad input to function
	}
	if(!(*rootPtr)){
		//must bracket dereference rootPtr becasue of order of operations
		current = (Node *)malloc(sizeof(Node));
		current->val = buffer;
		current->next = NULL;
		*rootPtr = current;
		return 1;
	}
	current = *rootPtr;
	if (alphaLess(buffer,current->val)){
		Node * temp;
		temp = (Node *)malloc(sizeof(Node));
		temp->val = buffer;
		temp->next = current;
		*rootPtr = temp;	

	} else {
		while(current->next && !(alphaLess(buffer, current->next->val))){
			current = current->next;
		}
		Node * temp;
		temp = (Node *)malloc(sizeof(Node));
		temp->val = buffer;
		temp->next = current->next;
		current->next = temp;
		
	}
return 0;
}
int printList(struct node * current){
	int num = 0;
	
	while(current){
		printf("%s", current->val);
		current = current->next;
		num++;
	}
	return num;
}
int alphaLess(char * left, char * right){
	//if returns true, left less than right
	for(;tolower(*left) == tolower(*right) && (*right || *left); left++, right++){}
	
	if (tolower(*left) < tolower(*right)){
		return 1;		
	}else{
		return 0;
	}
	
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

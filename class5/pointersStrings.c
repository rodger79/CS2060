#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void square(int * input) {
	*input= *input * *input;
}

int main(){
	
	char string[] = "The number is:";
	char *sPtr;
	//string[16] = 'j';
	
	sPtr = (char *)malloc(sizeof(char) *100);  	//cast void pointer into character pointer sizeof depends on OS multiply by 
											//number of characters; 100
	for(int i = 0;string[i];i++){
		sPtr[i] = string[i];

	}
	
	strcat(sPtr," 42");
	printf("%s",sPtr);
	puts("");
	
	return 0;
}

// int main(){
	
	// char string[] = "The number is:";
	////string[4] = 'i';
	
	// int val = 42;
	// square(&val); //send the address of val (by reference)
	// int *vPtr;
	// vPtr = &val; //assign the address of val to vPtr
	
	// char *sPtr;
	// sPtr = string;
	
	//puts(sPtr);
	// printf("%s %d %d",sPtr,*vPtr,val); //%s fo pointer, %d for variable so dereferenced
	// puts("");
	
	// return 0;
// }
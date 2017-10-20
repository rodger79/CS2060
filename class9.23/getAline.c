#include<stdio.h>
#include<stdlib.h>
#include<string.h>

size_t getAline(char ** bufferPtr){
	char * buffer = *bufferPtr; //declaration 
	size_t arraySize = 10;
	buffer = (char *)malloc(arraySize * sizeof(char));
	size_t index = 0;
	// while((buffer[index] = getchar()) != '\n' && (buffer[index] != EOF)){
	while((buffer[index] = getchar()) != EOF && (buffer[index++] != '\n')){ //quits if EOF without incrementing index
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

int main(){


	size_t bytes_read = 0; //generic type syze_t
	char * buffer; //memory address
	char * array[100];
	size_t index = 0;
	while ((bytes_read = getAline(&buffer)) !=0){ //& reference operator, send address of buffer which is itself a  memory address
		array[index++] = buffer;
	}
	
	for (int i = index -1; i >=0; i--){
		printf("%s", array[i]);
	}
	
	
	


}

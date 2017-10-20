#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printForward(char * buffer){

	int len = strlen(buffer);
	//reverse index for backwards
	for (int i = len; i>=0; i--){
		//strlen is index of last char (no null)
		putchar(buffer[i]);
	}

}

int main(){
	/*char buffer [100];
	char * lines [100];
	int i = 0;

	while (!feof(stdin)){
		scanf("%s", buffer);
		lines[i] = (char * ) malloc(strlen(buffer) + 1);
		strcpy(lines[i++], buffer);
	}
	for (int x = 0; x < i; x++){
		printf("%s ", lines[x]);
	}*/
	char buffer[] = "jason is here today after lots of beer\n";
	printForward(buffer);
	
return 0;
}

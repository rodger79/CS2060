#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mysteryFunct(char *x){
	char *marker;
	int count = 0;
	for(marker = x; *marker; ++marker)
		++count;
	return count;
}


void strcpy1(char * destString, char *sourceString){
	char *marker, *t;
	
	for (marker = sourceString, t = destString; *marker; marker++, t++)
	*t= *marker;

}

void do1(char * s, char *t){
	int  i =0, n= 0;
	char p;
	n = strlen(s);
	
	while((p=*s++)!='\0'){
		t[n-i-1] = p;
		i++;
	}
	return;
}
int getTemp(){
	return 5000;
}
int main(int argc, char * argv[]){

	/*
	
	int highTemp, lowTemp, currentTemp, complexTemp;
	complexTemp = getTemp();
	
	
	//highTemp = 
	//lowTemp = 
	//currentTemp = 


	
	char *Ptr;
	char *temp;
	
	temp = *&Ptr;
	temp = *&Ptr;
	temp = *Ptr;
	temp = Ptr;
	
	char source[] = {"C Programming"};
	char dest[14];
	
	do1(source,dest);
	for (int i=0; i<14;++i){
		printf("%c", dest[i]);
	}
	puts("");
		for (int i=0; i<14;++i){
		printf("%c", source[i]);
	}
	puts("");
	
	printf("%d\n", mysteryFunct(array));
	printf("%d\n", strlen(array));
	

	
	int fibiArray[] = {1,2,3,5,8,13,21,34,55,89};
	int primeArray[] = {2,3,5,7,11,13,17,19,23,29};
	int commonArray[9] = {0};
	int i,j;
	int n = 0;
	
	for (i=0; i<10;++i){
		for (j=0; j < 10; ++j){
			if (fibiArray[i] == primeArray[j]){
				commonArray[j] = primeArray[j];
				++n;
			}
		}
	}

	printf("The total number of common elements is %d\n", n);
	return 0;
	
	int value = 500;
	
	if (value > 0 && value <= 100 ){
		puts("pass");
	} else {
		puts("fail");
	}
	
	int x = 2;
	
	switch(x){
			case (1):
				//pickCard();
				puts("1");
				break;			
			case (2):
				puts("2");
				break;
			default:
				puts("This was not an option");
		}//endswitch
	
	int y = 10;
	
	for (int x = 0; x < y; x++){
		printf("%f\n", (float)x/y);
	}
	puts("");
	*/
	return 0;
}

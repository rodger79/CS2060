#include <stdio.h>
#include <pthread.h>

//use -pthread to compile
//gcc -pthread --std=c99 -Wall -o test threading.c && ./test

void * increment(void * xPtr_void){

	int * xPtr = (int *) xPtr_void;
	while((*xPtr)++ < 100);
	
	printf("increment finished\n");
	
	//must be returned so pthread knows it is done	
	return NULL;

}

int main(){

	int x = 0;
	int y = 0;

	printf("X:%d, y:%d\n",x,y);

	pthread_t inc_x_thread;
	pthread_t inc_y_thread;
	
	if(pthread_create(&inc_x_thread,NULL,increment, &x)){
		printf("Error creating threadx\n");
		return 1;
	}
	if(pthread_create(&inc_y_thread,NULL,increment, &y)){
		printf("Error creating thready\n");
		return 1;
	}
	if(pthread_join(inc_x_thread,NULL)){
		printf("Error Joining x\n");
	}

	if(pthread_join(inc_y_thread,NULL)){
		printf("Error Joining y\n");
	}
	printf("X:%d, y:%d\n",x,y);
		
return 0;
}

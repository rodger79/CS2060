#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include<string.h>
/*
//question 2
void strcpy1 (char * destString, char * sourceString) {
	char * marker, *t;
	
	for (marker = sourceString, t = destString; *marker; marker++,t++)
	*t = *marker;
	*t++ = '\0';
}*/

struct node{
	//data in our linked list
	int x;
	//self ref pointer
	struct node *next;
	struct node *previous;
};

void printForward(struct node * root){
	while(root){
		printf("%d ", root->x);
		root = root->next;
	}
}
void printBackward(struct node * root){
	while(root->next){

		root = root->next;
	}
	while(root){
		printf("%d ", root->x);
		root = root->previous;
	}
}

int insert(struct node ** rootPtr, int data){
	struct node * current;
	if(!(rootPtr)){
		return 0; //check for bad input to function
	}
	if(!(*rootPtr)){
		//must bracket dereference rootPtr becasue of order of operations
		current = (struct node *)malloc(sizeof(struct node *));
		current->x = data;
		current->next = NULL;
		current->previous = NULL;
		*rootPtr = current;
		return 1;
	}
	current = *rootPtr;
	if (data < current->x){/*
		current->previous = (Node *)malloc(sizeof(Node));
		current->previous->x = data;
		current->previous->previous = NULL;*/
		struct node * temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->x = data;
		temp->previous = NULL;
		temp->next = current;
		current->previous = temp;
		*rootPtr = temp;
		
	}else {
		while(current->next && current->next->x < data){
			current = current->next;
		}
		struct node * temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->x = data;
		temp->previous = current;
		temp->next = current->next;
		if (current->next){
			current->next->previous = temp;
		}
		
		current->next = temp;
		
	}
	return 0;
	current = *rootPtr;
	int count=0;
	while(current){
		current = current->next;
		count++;
	}
	return count;
	
}

int countNode(struct node * head, int x){
	struct node * current = head;
	int count = 0;
	while(current){
		if ( current->x == x)
		count++;
		current = current->next;
	}

return count;
}


int main(int argc, char ** argv){
	
	//seed rand
	srand(time(NULL));
	

	struct node * root = NULL;
	int count = 0;


	for (int i = 0; i<10; i++){
		count = insert(&root,rand()%10);		
	}
	
	insert(&root,5);
	insert(&root,11);
	printForward(root);
	//printf("size: %d\n", count);
	puts("");
	printBackward(root);
	puts("\n\n Value = 5");
	
	printf("count matches: %d\n", countNode(root, 5));
	/*
	//question 2

	char  source[] = "this is a test";
	char dest[] = "putting inn as longer";
	
	for (int i = 0; i < 10; i++){
		strcpy1 (dest, source);
	
		printf("%s\n", dest);
	}
	
	//Question 1

	//check for the correct arguments
	if (argc!= 2){
		fprintf(stderr, "%s: takes exactly one argument\n", argv[0]);
		return 1;	
	}
	float input = 0;
	
	input = atof(argv[1]);
	
	input = input * input * input;
	
	printf("%.4f\n", input);*/
	
return 0;	

}

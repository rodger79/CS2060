#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int val;
	struct node * next;
	struct node * back;
	
} Node;

int push_back(Node ** rootPtr, int data) {
	//needs node pointer pointer to send node * root by reference
	Node * current;
	
	if(!(rootPtr)){
		return 0; //check for bad input to function
	}
	
	if(!(*rootPtr)){
		current = (Node *)malloc(sizeof(Node));
		current->val = data;
		current->next = NULL;
		current->back = NULL;
		*rootPtr = current;
		return 1;
	}
	current = *rootPtr;
	int count = 1;
	while(current->next){
		current = current->next;
		count++;
	}
	current->next = (Node *)malloc(sizeof(Node));
	current->next->val = data;
	current->next->next = NULL;
	current->next->back = current;
	
	return count + 1;
	
}
int insert(Node ** rootPtr, int data){
	Node * current;
	if(!(rootPtr)){
		return 0; //check for bad input to function
	}
	if(!(*rootPtr)){
		//must bracket dereference rootPtr becasue of order of operations
		current = (Node *)malloc(sizeof(Node));
		current->val = data;
		current->next = NULL;
		current->back = NULL;
		*rootPtr = current;
		return 1;
	}
	current = *rootPtr;
	if (data < current->val){/*
		current->back = (Node *)malloc(sizeof(Node));
		current->back->val = data;
		current->back->back = NULL;*/
		Node * temp;
		temp = (Node *)malloc(sizeof(Node));
		temp->val = data;
		temp->back = NULL;
		temp->next = current;
		current->back = temp;
		*rootPtr = temp;
		
	}else {
		while(current->next && current->next->val < data){
			current = current->next;
		}
		Node * temp;
		temp = (Node *)malloc(sizeof(Node));
		temp->val = data;
		temp->back = current;
		temp->next = current->next;
		if (current->next){
			current->next->back = temp;
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
void printForward(Node * root){
	while(root){
		printf("%d ", root->val);
		root = root->next;
	}
}
void printBackward(Node * root){
	while(root->next){

		root = root->next;
	}
	while(root){
		printf("%d ", root->val);
		root = root->back;
	}
}
int main(){
	Node * root = NULL;
	int count = 0;


	for (int i = 0; i<10; i++){
		count = insert(&root,rand()%10);		
	}
	insert(&root,5);
	insert(&root,11);
	printForward(root);
	printf("size: %d\n", count);
	printBackward(root);
	puts("\n");
	

return 0;
}

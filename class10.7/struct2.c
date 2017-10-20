#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node * next;

} Node;


Node * append (Node * root, int input){
	if (!root){
		//if root is null, allocate
		root = (Node *) malloc (sizeof(Node));
		root->data = input;
		root->next = NULL;
	}else{

		Node * current = root;
		while(current->next){current = current->next;}
		current->next = (Node *) malloc (sizeof(Node));
		current->next->data = input;
		current->next->next = NULL;
	}
	return root;
}

Node * insert (Node * root, int input){
	if (!root){
		//if root is null, allocate
		root = (Node *) malloc (sizeof(Node));
		root->data = input;
		root->next = NULL;
	}else if(input <= root->data){
		//input is less then first node, need to put first
		Node * current = (Node *) malloc (sizeof(Node));
		current->next = root;
		root = current;
		current->data = input;
	}else{
		Node * current = root;
		//must check current->next exists before anything else && does first eval first
		//	second eval is not done
		//current keeps moving until input is greater than than next
		//after that current is the node before where we want to insert
		while(current->next && input > current->next->data){
			current = current->next;
		}
		//temp node
		Node * temp = (Node *) malloc (sizeof(Node));
		temp->data = input;
		temp->next = NULL;
		//insert after current and before current->next
		temp->next = current->next;
		current->next = temp;
	}
	return root;
}
void printList (Node * root){
	Node * current = root;
	while (current){
		printf("%d ", current->data);
		current = current->next;
	}
	puts("");
};

int main(){

	Node * root = NULL;
	for (int i = 0; i <100;i++){
		root = insert(root,rand() %43);
	}
	root = insert(root,2);
	root = insert(root,42);
	root = insert(root,3);
	root = insert(root,2);

	printList (root);

	

}

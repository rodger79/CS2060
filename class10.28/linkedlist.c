#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
	char * color;
	struct node * next;
};

struct node * push_back(struct node * root, char * color){
	struct node * temp;
	struct node * current = root;
	
	temp = (struct node *) malloc (sizeof(struct node));
	temp->color = color;	
	temp->next = NULL;
	if (root == NULL){
		return temp;
	}
	while (current->next){current = current->next;} //current next has a value, finds end of list
	//current now last known value
	current->next = temp;
	return root;
	
}
int printList(struct node * current){
	int num = 0;
	
	while(current){
		printf("%s\n", current->color);
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
int main(){

	char * colors[] = {"green", "red", "blue", "black", "Seafoam", "Sea"};
	if (alphaLess(colors[4],colors[5])){
		printf("%s is less than %s\n", colors[4],colors[5]);
	} else {
		printf("%s is more than %s\n", colors[4],colors[5]);
	}
	struct node * root = NULL;
	for (int i = 0; i < 10; i++){
		root = push_back(root,colors[rand() %5]);
	}
	printList(root);
	
return 0;
}

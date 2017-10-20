#include <stdio.h>
#include <string.h>

struct node {

	char name[100];
	int value;
	char character;
	//look for null to find end of list
	struct node * next; //just a pointer 4 bytes
	struct node * back;
 	//	struct node otherStruct;  can't be done, recurse without end	
};

int changeNode(struct node in){
	in.name[3] = 'S';
	return 0;
	
}
int changeNodePtr(struct node * in){
	in->name[3] = 'S';
	return 0;
	
}
int changeString(char * in){
	in[3] = 'S';
	return 0;
	
}

int main(){

	struct node mainNode, secondNode;
	strcpy(mainNode.name,"jason");
	puts(mainNode.name);
	changeNodePtr(&mainNode);
	puts(mainNode.name);
	
	secondNode = mainNode;
	
	mainNode.next = &secondNode;
	puts(mainNode.next->name);
	
	printf("size: %lu\n", sizeof(struct node));
		
	
	
	/* don't do this
	if(mainNode == secondNode){

	}*/
	
/*	changeString(mainNode.name);
	puts(mainNode.name);
	changeNode(mainNode);
	secondNode = mainNode;
	changeString(mainNode.name);
	puts(mainNode.name);
	puts(secondNode.name);*/
}

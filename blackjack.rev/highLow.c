#include <stdio.h> //#include cut and pastes info from the header file
#include <stdlib.h> //includes rand
#include <time.h>

//declarations
void clearBuff();
int pickCard();
int deal();
int highLow();
void printHand(int * hand, int handType);

int clearHand(int hand[21]){

	for (int i = 0; i < 21; i++){
		hand[i] = -1;
	}
return 0;
}

int totalHand(int hand[]){
	int total = 0;
	for (int i = 0; hand[i] != -1; i++){
		total += hand[i];
	}
	if (total > 21){
		for (int i = 0; hand[i] != -1; i++){
			if(hand[i] == 11){
				hand[i] = 1;
				total = totalHand(hand);
				break;
			}
		}
	}
	return total;
}

int dealHand( int hand[]){
	int i = 0;
	for (; hand[i] != -1; i++){}
	hand[i] = deal();
	return 0;
}
// main
int main(){

	srand(time(NULL));
//	printf("card: %d", deal());
	int dealer [21];
	int player [21];
	
	int money = 1;
	
	puts("welcome");
	
	while (money > 1){

		clearHand(dealer);
		clearHand(player);
				
		dealHand(dealer);
		dealHand(player);		

		dealHand(dealer);
		dealHand(player);
		
	
		printf("Dealer: ");
		printHand(dealer,1);

		int choice = -1;		
		do{
			printf("Player: ");
			printHand(player,0);
		

			while(choice != 1 && choice !=2) {
			
				printf("Total: %d --Do you want to 1) Hit or 2) Stay:", totalHand(player));
				scanf("%d", &choice);
				clearBuff();
			
				if(choice != 1 && choice !=2){
					printf("\n Illegal option");
				}
		
			}
			if(choice ==2){
				break;
			}else{
				dealHand(player);
			}
		} while(choice != 2 && totalHand(player) < 21);
		
		puts("");

		
		while(totalHand(dealer) < 17){
			dealHand(dealer);
		
		}
	break;
	}
	
	puts("Dealer: ");
	printHand(dealer,1);
	puts("");
	puts("Player: ");
	printHand(player,0);
	
		
	if(totalHand(player) > 21) {
		puts("you lose, busted");
	} else if (totalHand(dealer) > 21){
		puts ("dealer busted");
	} else if (totalHand(player)>totalHand(dealer)){
		puts("you win");
	} else {
		puts("you lose");
	}

	puts("");
	return 0;

}
void printHand(int * hand, int handType){
	if (handType){
		printf("* ");
		for (int i=1;hand[i] != -1; i++){
			printf("%d ",hand[i]);
		}
	}else{
		for (int i=0;hand[i] != -1; i++){
			printf("%d ",hand[i]);
		}
	}
	puts("");
}
//highLow game
int highLow(){
		
	int player [10];
	int dealer [10];
	int dealCount = 0;
	puts("Welcome to High Low");
	int wifeWallet = 100;
	char choice = 'x';
	
	while(dealCount < 10){
		printf("$%d in chips\n", wifeWallet);
		
		player[dealCount] = deal();
		dealer[dealCount++] = deal();
		
		printHand(dealer,dealCount);
		// for (int i=0;i< dealCount; i++){
			// printf("%d ",dealer[i]);
		// }
		// puts("");
		
		for(;;){ //old school infinite loop
			puts("Would you like to bet high or low? h or l");
			scanf("%c", &choice);
			clearBuff();
			if (choice != 'l' && choice != 'h'){
				puts("Not a correect value");
			}else {
				break;//picked correctly
			}
			
		}
		// for (int i=0;i< dealCount; i++){
			// printf("%d ",player[i]);
		// }
		// puts("");
		printHand(player,dealCount);
		
		if(choice == 'h' && dealer[dealCount-1] < player[dealCount])
			wifeWallet+=10;
		else if (choice == 'l' && dealer[dealCount-1] > player[dealCount])
			wifeWallet+=10;
		else
			wifeWallet-=10;
	}
	
return 0;
}

//clear the OS buffer
void clearBuff(){
	char junk;
	while((junk= getchar()) != EOF && junk != '\n'); //no comparing strings inside of an if statement only char
}

//play pickCard
int pickCard(){


	int correct = deal();
	int guess = 0;	
	
	
	printf("Enter 0 to quit\n");
	while (1){

		printf("Pick a card!\n");
		scanf("%d",&guess); 
		clearBuff();//clears the buffer incase of incorrect input required for all scanf
		
		if(guess==0){
			break;
		}
		if (guess < 2 || guess >11){
			puts("whatdid you not understand about cards?"); //puts -output with newline and only one argument
			
			continue;
		}
		
		if(guess == correct){
			puts("grats!");
			break;
		}else if (guess > correct){
			puts("too high");
		}else {
			puts("too low");
		}
	}
	return 0;
}


//deal a card
//precondition that rand is seeded
int deal(){
	int deck[] = {2,3,4,5,6,7,8,9,10,10,10,10,10,11};
	int correct = deck[(rand() % 13)]; 
	return correct;
}

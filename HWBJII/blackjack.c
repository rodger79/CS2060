//Filename:			blackjack.c
//Student Name:		Rodger Byrd
//Date:				9-13-15
//Purpose:			Game to play Blackjack
//How to use:		execute the output and use the console to play the game



#include <stdio.h> //#include cut and pastes info from the header file
#include <stdlib.h> //includes rand
#include <time.h>
#include <string.h>

//declarations
void clearBuff();
int pickCard();
int deal();
int highLow();
int blackjack();
int printHand();
void printBJhand();
int blackJackTotal();

//Function: main
//Prototype with arg Types: No Arguments
//How to use: Runs automatically
//What it does: Lets you choose a game
int main(){
	
	//seed rand
	srand(time(NULL));
	
	//interface menu for choosing games
	char choice = 'x';
	while(choice !='q'){
		puts("\nWould you like to play a game:");
		puts("1: Blackjack");
		puts("2: High Low");
		puts("3: Pick Card");
		puts("4: Deal Test");
		puts("q to quit");
		scanf("%c",&choice);
		clearBuff();
		
		puts("");
		switch(choice){
			case ('1'):
				blackjack();
				break;			
			case ('2'):
				highLow();
				break;
			case ('3'):
				pickCard();
				break;
			case ('q'):
				return 0;
			default:
				puts("This was not an option");
		}//endswitch
		puts("");
		
	}
	return 0;

}

//Function: printHand
//Prototype with arg Types: int printHand(int *, int);
//How to use: call to print hand to interface
//What it does: outputs current hand to interface
int printHand(int * hand, int dealCount){
	for (int i=0;i< dealCount; i++){
		printf("%d ",hand[i]);
	}
	puts("");
	return 0;
}
//Function: printBJhand
//Prototype with arg Types: int printBJhand(int*, int, int);
//How to use: call to print hand to interface, pass in * of hand, and set int to player vs dealer and use 
//					all to show/hide the hole card
//What it does: outputs current blackjack hand to interface
void printBJhand(int * deck, int player, int all) {
	
	if (player){
		//print player version of output
		printf("Player's cards are: ");
		for(int i = 0;deck[i];i++){
			if (deck[i] == 11){
				printf("A ");
			} else {
				printf("%d ",deck[i]);
			}
		}
	} else {
		//print dealer version of output
		//hide hole card if all is not set
		if (all){
			for(int i = all;deck[i];i++){
				if (deck[i] == 11){
					puts("Dealer is showing an Ace");
				} else {
					printf("Dealer is showing: %d\n",deck[i]);
				}
			}
		} else {
			printf("Dealer's cards are: ");
			for(int i = all;deck[i];i++){
				if (deck[i] == 11){
					printf("A ");
				} else {
					printf("%d ",deck[i]);
				}
			}
		}
	}

}
//Function: blackJackTotal
//Prototype with arg Types: int blackJackTotal(int*);
//How to use: call to add up the value of a hand, retuns the total for the hand that was passed in
//What it does: returns total value of hand and calculates for Aces
int blackJackTotal(int * deck){
	int total = 0;
	int numAces = 0;
	int numAcesChanged = 0;
	//total face value
	for (int i = 0; deck[i]; i++){
		if (deck[i] == 11){
		numAces++;
		}
		total += deck[i];
	}

	//if total is over 21, check for aces to see if they can be counted as 1
	while (total > 21){
		if (numAces == 0){
			break;
		} else {
			//have at least 1 ace in hand re test score
			//and 
			if (numAces > numAcesChanged){
				//existing aces currently counted as 11
				//convert to 1 and decrement numAcesChanged
				total-=10;
				numAcesChanged++;
			} 
			else {
				//all aces converted to 1
				break;
			}
		}
	}
	return total;
}
//Function: blackjack
//Prototype with arg Types: 
//					none
//How to use: call to play blackjack
//What it does: provides the logic and interface for blackjack
int blackjack(){
	
	int bank = 0;
	int bet = 0;
	int minimumBet = 10;
	int *playerPtr;
	int *dealerPtr;
	char hit = 'x';
	int pTotal = 0;
	int dTotal = 0;
	int pScore = 0;
	int dScore = 0;

	
	playerPtr = (int *)malloc(sizeof(int) *22);  
	dealerPtr = (int *)malloc(sizeof(int) *22);  

	
	puts("Welcome to Blackjack\n");
	

	for(;;){ //old school infinite loop
		printf("How much do you have to gamble today?\n");
		scanf("%d",&bank); 
		clearBuff();
		if (bank  < 0){
			puts("Not a correect value");
		} else if (bank < 10){
			puts("\nYou should probably be on the penny slots");
			puts("you must have at least 10 to play\n");
		} else {
			//set minimum bet
			if (bank <101 ) {
				puts("this will be short...");
			} else if (bank > 5000 && bank <50000 ){
				minimumBet = 50;
			} else if (bank >= 50000){
				puts("Welcome High roller!\n");
				minimumBet = 1000;
			} else {
				//do nothing
			}
			break;//picked correctly
		}
	}
	
	
	while(bank > 0){
		
		//clear hand
		memset(playerPtr,0, sizeof(int) * 22);
		memset(dealerPtr,0, sizeof(int) * 22);
		pTotal = 0;
		dTotal = 0;

		
		//print minimum bet
		printf("Minimum bet is $%d in chips\n", minimumBet);
		
		//place bets
		for(;;){ //old school infinite loop
			puts("========================================");
			printf("Place your bet or 0 to quit.\n");
			scanf("%d",&bet); 
			clearBuff();
			if (bet == 0){
				exit(0);
			} else if (bet < minimumBet) {
				printf("minimum bet is %d \n", minimumBet);
			} else if ( bet > bank ){
				puts("You can't bet more than you have");
			}else {
				//correct
				printf("your bet is %d \n", bet);
				break;
			}
		}
		puts("");
		
		//deal hands
		for( int i = 0; i < 2; i++){
			playerPtr[i] = deal();
			dealerPtr[i] = deal();
			pTotal++;
			dTotal++;
		}

		
		while (1){
		
			//show hands without dealer face down card
			printBJhand(playerPtr,1,1);		
			puts("");
			printBJhand(dealerPtr,0,1);
			
			//check for blackjack
			if ( (dealerPtr[0] == 11 && dealerPtr[1] == 10) || (dealerPtr[0] == 11 && dealerPtr[1] == 10) ){
				//dealer blackjack
				puts("========================================");
				puts("Dealer has Blackjack - Push\n");
				break;
			} else {
				//continue
			}
			
			
			//no dealer blackjack 
			for(;;){ //old school infinite loop
				puts("Would you like to hit or stick? h or s");
				scanf("%c", &hit);
				clearBuff();
				if (hit != 's' && hit != 'h'){
					puts("Not a correect value");
				}else {
					break;//picked correctly
				}
			}
			if (hit == 'h'){
				playerPtr[pTotal++] = deal();
				
				//get current total 
				pScore = blackJackTotal(playerPtr);
				
				if (pScore > 21 ){
					puts("========================================");
					puts("\n You are busted! \n");
					
					bank -= bet;
					//show hands with dealer face down card
					printBJhand(playerPtr,1,0);		
					printf(" Total: %d", pScore);
					printf("\nYour balance is now %d\n", bank);
					break;
				}
				
			} else {
				puts("========================================");
				dScore = blackJackTotal(dealerPtr);
				pScore = blackJackTotal(playerPtr);
				
				//loop through dealer hand and deal until hand value is greater than 17
				while (dScore <=17 ){
					puts("Dealer hand less than 17, Dealer hits:");
					dealerPtr[dTotal++] = deal();
					dScore = blackJackTotal(dealerPtr);
					//show dealer hands
					printBJhand(dealerPtr,0,0);
					puts("\n");
				}
				if (dScore > 17){
					//check for winner
					if (dScore > 21 ){
						puts("Dealer Busts\n");
						bank += bet;
					} else if (dScore > pScore){
						puts("You lose\n");
						bank -= bet;
					} else if (dScore == pScore) {
						puts("push\n");
					} else{
						puts("You win!\n");
						bank += bet;
					}
					//show hand values to the interface
					printBJhand(playerPtr,1,0);		
					printf(" Total: %d", pScore);
					puts("");
					printBJhand(dealerPtr,0,0);
					printf(" Total: %d", dScore);
					printf("\nYour balance is now %d\n", bank);
				} 
				break;
			}	
		}
	}//end while
return 0;
}

//Function: highLow
//Prototype with arg Types: 
//					int highLow();
//How to use: call to play highLow
//What it does: provides the logic and interface for highLow
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
//Function: clearBuff
//Prototype with arg Types: 
//					void clearBuff();
//How to use: call to clear the buffer
//What it does: clear the OS buffer
//
void clearBuff(){
	char junk;
	while((junk= getchar()) != EOF && junk != '\n'); //no comparing strings inside of an if statement only char
}

//Function: pickCard
//Prototype with arg Types: 
//					int pickCard();
//How to use: call to play pickCard
//What it does: provides the logic and interface for pickCard
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

//Function: deal
//Prototype with arg Types: 
//					int deal();
//How to use: call to deal and return an int card
//What it does: randomly chooses a card out of the array,precondition that rand is seeded
int deal(){
	int deck[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
	int card = deck[(rand() % 13)]; 
	return card;
}
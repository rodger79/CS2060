//Filename:			bjblackjack.c
//Student Name:		Rodger Byrd
//Date:				11-4-15
//Purpose:			Game to play Blackjack with face cards and structure
//How to use:		execute the output and use the console to play the game



#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>

//declarations
void clearBuff();
int blackjack();
void printBJhand();
int blackJackTotal();

typedef struct card {
	char * face;
	char * suit;
	int * value;

}Card;


int main (int argc, char ** argv){

	//seed rand
	srand(time(NULL));

		
	//interface menu for choosing games
	char choice = 'x';
	while(choice !='q'){
		puts("\nWould you like to play a game:");
		puts("1: Blackjack");
		puts("q to quit");
		scanf("%c",&choice);
		clearBuff();
		
		puts("");
		switch(choice){
			case ('1'):
				blackjack();
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

//Function: blackjack
//Prototype with arg Types: 
//					none
//How to use: call to play blackjack
//What it does: provides the logic and interface for blackjack
int blackjack(){
	
	int bank = 0;
	int bet = 0;
	int minimumBet = 10;

	char hit = 'x';
	int pTotal = 0;
	int dTotal = 0;
	//int deckIndex = 0;
	
	int pScore = 0;
	int dScore = 0;
	int show = 1;
	int hide = 0;
	int player = 1;
	int dealer = 0;
	
	Card * nextCard;
	//int *playerPtr;
	//int *dealerPtr;
	//Card aCard;
	//creat and array of card
	Card deck[52];
	Card dealerHand[22];
	Card playerHand[22];
	nextCard = deck;


	char * faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
				"Jack", "Queen", "King"};
	char * suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
	int  value[] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
	
	
	//print deck
	for (int i = 0; i< 13; i++){
		for (int x = 0; x < 4; x++){ 
			nextCard->face = faces[i]; 
			nextCard->suit = suits[x];			
			nextCard->value = &value[i];
			nextCard++;
		}
	}
	
	/*
	//print
	for (int i = 0; i < 52; i++){
	
		printf("%s of %s, value: %d,\n", deck[i].face, deck[i].suit, deck[i].value);
	}
	*/
	
	//convert everything below to use the single deck, not an infinite deck
	
	//allocate new space for hands
	
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
				puts("this will be a short game");
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
			

		pTotal = 0;
		dTotal = 0;
		
		//shuffle
		puts("Shuffling the deck......");
		for (int i = 0; i < 52; i++){
		
			int random = rand()%52;
			Card temp = deck[i];	
			deck[i] = deck[random];
			deck[random] = temp;
			//printf("%s of %s\n", temp.face, temp.suit);
		}
		// allow for nextCard++
		nextCard = deck;
		
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
		//could convert to loops

		playerHand[pTotal] = * nextCard;
		nextCard++;
		pTotal++;

		dealerHand[dTotal]  = * nextCard;
		nextCard++;
		dTotal++;
		
		playerHand[pTotal]  = * nextCard;
		nextCard++;
		pTotal++;

		dealerHand[dTotal]  = * nextCard;
		nextCard++;
		dTotal++;
		
		while (1){
		
			//show hands without dealer face down card
			
			////FIX HERE
			/////
			////
			
			printBJhand(&playerHand,player,pTotal, hide);		
			printBJhand(&dealerHand,dealer,dTotal, hide);
			
			//check for blackjack
			if ( (* dealerHand[0].value == 11 && * dealerHand[1].value == 10) || (* dealerHand[1].value == 11 && * dealerHand[0].value == 10) ){
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
			
				playerHand[pTotal]  = * nextCard;
				nextCard++;
				pTotal++;
				
				//get current total 
				pScore = blackJackTotal(&playerHand,pTotal);
				
				if (pScore > 21 ){
					puts("========================================");
					puts("\n You bust! \n");
					
					bank -= bet;
					//show hands with dealer face down card
					printBJhand(&playerHand,player,pTotal, hide);		
					puts("");
					printf(" Total: %d", pScore);
					printf("\nYour balance is now %d\n", bank);
					break;
				}
				
			} else {
				puts("========================================");
				dScore = blackJackTotal(&dealerHand,dTotal);
				pScore = blackJackTotal(&playerHand,pTotal);
				
				//loop through dealer hand and deal until hand value is greater than 17
				while (dScore <=17 ){
					puts("Dealer hand less than 17, Dealer hits:");
					dealerHand[dTotal]  = * nextCard;
					nextCard++;
					dTotal++;
					dScore = blackJackTotal(&dealerHand,dTotal);
					//show dealer hands
					//printBJhand(&dealerHand,dealer,dTotal, show);		

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
						puts("It's a push\n");
					} else{
						puts("You win!\n");
						bank += bet;
					}
					//show hand values to the interface
					printBJhand(&playerHand,player,pTotal, hide);		
					printf(" Total: %d", pScore);
					puts("");
					printBJhand(&dealerHand,dealer,dTotal, show);		
					printf(" Total: %d", dScore);
					printf("\nYour balance is now %d\n\n", bank);

				} 
				break;
			}	
		}
		if (bank == 0 ) {
			puts("looks like you are out of chips, how would you like a buffet coupon?");
		}
	}//end while
	
	
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


//Function: printBJhand
//Prototype with arg Types: int printBJhand(int*, int, int);
//How to use: call to print hand to interface, pass in * of hand, and set int to player vs dealer and use 
//					all to show/hide the hole card
//What it does: outputs current blackjack hand to interface
void printBJhand(Card * hand, int player, int length, int showDealer) {
	
	if (player){
		//print player version of output
		puts("Player hand showing: \n");
		//print
		for (int i = 0; i < length; i++){
	
			printf("-%s of %s\n", hand[i].face, hand[i].suit);
		}
	} else {
		//print dealer version of output
		if (showDealer){
			puts("Dealer hand showing: \n");
			//print
			for (int i = 0; i < length; i++){
				printf("-%s of %s\n", hand[i].face, hand[i].suit);
			}			
		} else {
			puts("Dealer hand showing: \n\n-Facedown Card");
			//print
			for (int i = 1; i < length; i++){
				printf("-%s of %s\n", hand[i].face, hand[i].suit);
			}
		}
	}
	puts("");
}

//Function: blackJackTotal
//Prototype with arg Types: int blackJackTotal(int*);
//How to use: call to add up the value of a hand, retuns the total for the hand that was passed in
//What it does: returns total value of hand and calculates for Aces
int blackJackTotal(Card * hand, int length ){
	
	int total = 0;
	int numAces = 0;
	int numAcesChanged = 0;
	
	//total face value
	for (int i = 0; i < length; i++){
		if (*hand[i].value == 11){
		numAces++;
		}
		total += *hand[i].value;
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

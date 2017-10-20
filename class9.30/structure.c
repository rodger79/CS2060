#include <stdio.h>


typedef struct card {
	char * face;
	char * suit;

}Card;


int main (int argc, char ** argv){

	char * faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
				"Jack", "Queen", "King"};
	char * suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};

	Card * nextCard;
	//Card aCard;
	//creat and array of card
	Card deck[52];
	nextCard = deck;
	// allow for nextCard++
	
	

	
	for (int i = 0; i< 13; i++){
		for (int x = 0; x < 4; x++){
			nextCard->face = faces[i]; 
			nextCard->suit = suits[x];			
			//(*nextCard).face = faces[i]; order of operations!
			//(*nextCard).suit = suits[x]; "." means (member of)
			nextCard++;
		}
	}


	//shuffle
	for (int i = 0; i < 52; i++){
		//need to seed rand
		int random = rand()%52;
		Card temp = deck[i];	
		deck[i] = deck[random];
		deck[random] = temp;
		//printf("%s of %s\n", temp.face, temp.suit);
	}
	
	//print
	for (int i = 0; i < 52; i++){
	
		printf("%s of %s\n", deck[i].face, deck[i].suit);
	}
}

#include <stdio.h> //#include cut and pastes info from the header file
#include <stdlib.h> //includes rand
#include <time.h>

//declarations
void clearBuff();
int pickCard();
int deal();
int highLow();
int printHand();

// main
int main(){

	char choice = 'x';
	while(choice !='q'){
		puts("Would you like to play a game:");
		puts("1: pickCard");
		puts("2: High Low");
		puts("3: Global Thermonuclear War");
		puts("q to quit");
		scanf("%c",&choice);
		clearBuff();
		
		// if(choice == '1'){
			// pickCard();
		// }else if(choice == '2'){
			// puts("This is not a wise choice");
		// }else{
			//puts ("that was not an option";
		//}
		puts("");
		switch(choice){
			case ('1'):
				pickCard();
				break;			
			case ('2'):
				highLow();
				break;
			case ('3'):
				puts("This is not a wise choice");
				break;
			case ('q'):
				return 0;
			default:
				puts("This was not an option");
		}//endswitch
		puts("");
		
	}
	return pickCard();

}
int printHand(int * hand, int dealCount){
	for (int i=0;i< dealCount; i++){
		printf("%d ",hand[i]);
	}
	puts("");
	return 0;
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
	srand(time(NULL));

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
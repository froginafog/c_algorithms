//Classify poker hands
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RANKS 13  //2, 3, 4, 5, 6, 7, 8, 9, T, J,  Q,  K,  A         
                  //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12    (rank index)
#define SUITS 4   //D = diamond, C = club, H = heart, S = space  
                  //0          , 1        , 2        , 3        (suit index)
#define CARDS 5   //5 cards per poker hand

int ranks[RANKS];
int suits[SUITS];
bool cardExists[RANKS][SUITS];
bool three, four, flush, straight;
int pairs;  //0, 1, 2

void readCards(void);
void printCards(void);
void analyzeHand(void);
void printResult(void);
void pauseForSomeTime(void);

int main()
{
	int numberOfGames;
	
	for(numberOfGames = 1; numberOfGames < 100; numberOfGames++)
	{
		printf("game %d\n", numberOfGames);
		readCards();
		printCards();
		analyzeHand();
		printResult();

		pairs = 0;
		three = false;
		four = false;
		flush = false;
		straight = false;
		pauseForSomeTime();
		printf("------------------------------------------------------------------------\n");
	}
	
	return 0;
}

void readCards(void)
{
	int rank;
	int suit;
	int numberOfCards;
	int minRank = 0;
	int maxRank = RANKS - 1;
	int minSuit = 0;
	int maxSuit = SUITS - 1;
		
	for(rank = 0; rank < RANKS; rank++)
	{
		ranks[rank] = 0;
	}
	
	for(suit = 0; suit < SUITS; suit++)
	{
		suits[suit] = 0;
	}
	
	for(rank = 0; rank < RANKS; rank++)
	{
		for(suit = 0; suit < SUITS; suit++)
		{
			cardExists[rank][suit] = false;
		}
	}
	
	srand(time(NULL));
	
	numberOfCards = 0;
	while( numberOfCards < CARDS)
	{		
		rank = rand() % (maxRank - minRank + 1) + minRank;  
		suit = rand() % (maxSuit - minSuit + 1) + minSuit;  
		
		if(cardExists[rank][suit] == false)  //make sure that duplicate cards are not included 
		{
			ranks[rank]++;
			suits[suit]++;
			cardExists[rank][suit] = true;
			numberOfCards++;
		}
	} 
	
}

void printCards(void)
{
	int cardCount;
	int rank;
	int suit;
	char rankCh;
	char suitCh;
	
	cardCount = 0;
	while(cardCount < CARDS)
	{
		for(rank = 0; rank < RANKS; rank++)
		{
			for(suit = 0; suit < SUITS; suit++)
			{
				if(cardExists[rank][suit] == true)
				{	
					switch(rank)
					{
						case 0:  rankCh = '2';
								 break;
						case 1:  rankCh = '3';
								 break;
						case 2:  rankCh = '4';
								 break;
						case 3:  rankCh = '5';
								 break;
						case 4:  rankCh = '6';
								 break;
						case 5:  rankCh = '7';
								 break;
						case 6:  rankCh = '8';
								 break;
						case 7:  rankCh = '9';
								 break;
						case 8:  rankCh = 'T';
								 break;
						case 9:  rankCh = 'J';
								 break;
						case 10: rankCh = 'Q';
								 break;
						case 11: rankCh = 'K';
								 break;
						case 12: rankCh = 'A';
								 break;
						default: printf("invalid rank\n");
								 exit(EXIT_SUCCESS);
					}
					
					switch(suit)
					{
						case 0: suitCh = 'D';
								break;
						case 1: suitCh = 'C';
								break;
						case 2: suitCh = 'H';
								break;
						case 3: suitCh = 'S';
								break;
						default: printf("invalid suit\n");
								 exit(EXIT_SUCCESS);	
					}
					
					printf("%c", rankCh);
										
					switch(suitCh)
					{
						case 'D': printf(" of Diamond   ");
								  break;
						case 'C': printf(" of Club   ");
							      break;
						case 'H': printf(" of Heart   ");
								  break;
						case 'S': printf(" of Spade   ");
								  break;
					}
					
					cardCount++;
					if(cardCount == CARDS)
					{
						printf("\n");
						return;
					}
				}
			}
		}
	}
	
	printf("\n");
}

void analyzeHand(void)
{
	int numberOfConsecutiveCards = 0;
	int rank;
	int suit;
	
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;
	
	//check for flush
	for(suit = 0; suit < SUITS; suit++)
	{
		if(suits[suit] == CARDS)
		{
			flush = true;
		}
	}
	
	//check for straight
	for(rank = 0; rank < RANKS; rank++)
	{
		if(ranks[rank] > 0)
		{
			numberOfConsecutiveCards++;
		}
		else
		{
			numberOfConsecutiveCards = 0;
		}
		
		if(numberOfConsecutiveCards == CARDS)
		{
			straight = true;
			return;  //if we have a straight then we can't have pairs, three, or four
		}
	}
	
	//check for {A, 2, 3, 4, 5} straight
	numberOfConsecutiveCards = 0;
	rank = 13;
	if(ranks[rank] > 0)
	{
		numberOfConsecutiveCards++;
	}
	
	for(rank = 0; rank < 3; rank++)
	{
		if(ranks[rank] > 0)
		{
			numberOfConsecutiveCards++;
		}
		else
		{
			numberOfConsecutiveCards = 0;
		}
		
		if(numberOfConsecutiveCards == CARDS)
		{
			straight = true;
			return;  //if we have a straight then we can't have pairs, three, or four
		}
	}
	
	//check for four of a kind, three of a kind, pairs
	for(rank = 0; rank < RANKS; rank++)
	{
		if(ranks[rank] == 4)
		{
			four = true;
			return;
		}
		else if(ranks[rank] == 3)
		{
			three = true;
		}
		else if(ranks[rank] == 2)
		{
			pairs++;
		}
	}
}

void printResult(void)
{
	if(straight == true && flush == true)
	{
		printf("Straight Flush\n");
	}
	else if(four == true)
	{
		printf("Four of a kind\n");
	}
	else if(three == true && (pairs == 1) == true)
	{
		printf("Full House\n");
	}
	else if(flush == true)
	{
		printf("Flush\n");
	}
	else if(straight == true)
	{
		printf("Straight\n");
	}
	else if(three == true)
	{
		printf("Three of a kind\n");
	}
	else if(pairs == 2)
	{
		printf("Two Pairs\n");
	}
	else if(pairs == 1)
	{
		printf("Single Pair\n");
	}
	else
	{
		printf("Highest Card\n");
	}
}

void pauseForSomeTime(void)
{
	unsigned int i;
	
	for(i = 0; i < 500000000; i++)
	{
	}
}

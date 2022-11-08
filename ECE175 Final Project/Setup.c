
// TODO: Find a way to create a linked list from inside a fuction so that it does not need to be initalized in main then populated from the function

//#include "LL Management.c"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc & calloc

#define DECKSIZE 37

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 9, 10 (queen)
	struct card_s* next;
} card;

card node_create(char suit, int face);

void create_decklist(void) // This may need to be moved to main, nodes created here may go out of scope upon returning to main
{
	card current;
	card* P_cur = &current;
	P_cur = (card*)calloc(DECKSIZE, sizeof(card));

	for (int s = 1; s <= 9; ++s) // Spades
	{
		*P_cur = node_create('s', s);
		P_cur++;
	}
	for (int d = 1; d <= 9; ++d) // Diamonds
	{
		*P_cur = node_create('d', d);
		P_cur++;
	}
	for (int c = 1; c <= 9; ++c) // Clubs
	{
		*P_cur = node_create('c', c);
		P_cur++;
	}
	for (int h = 1; h <= 9; ++h) // Hearts
	{
		*P_cur = node_create('h', h);
		P_cur++;
	}
	*P_cur = node_create('h', 10); // Queen of Hearts
	return;
}
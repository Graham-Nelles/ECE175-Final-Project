
// TODO: Find a way to create a linked list from inside a fuction so that it does not need to be initalized in main then populated from the function

#include "LL Management.c"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 9, 10 (queen)
	struct card_s* next;
} card;

void create_decklist(card* header) // This may need to be moved to main, nodes created here may go out of scope on returning to main
{
	card* P_cur;
	card temp;
	for (int s = 1; s <= 9; ++s) // Spades
	{
		node_create("s", s);
	}
	for (int d = 1; d <= 9; ++d) // Diamonds
	{
		node_create("d", d);
	}
	for (int c = 1; c <= 9; ++c) // Clubs
	{
		node_create("c", c);
	}
	for (int h = 1; h <= 9; ++h) // Hearts
	{
		node_create("h", h);
	}
}
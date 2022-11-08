
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

// LL Management.c
card node_create(char suit, int face);
void node_print_debug(card target);

// Setup.c
void create_decklist(void);

int main(void)
{


	create_decklist();

	for (int i = 0; i < 3; ++i)
	{
		
	}

	return 0;
}
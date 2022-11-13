
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc & calloc

#define DECKSIZE 41

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 10, 11 (queen)
	struct card_s* next;
} card;

// LL Management.c
card node_create(card* target, char suit, int face);
void node_print_debug(card* target);

// Setup.c
void create_decklist(card* head);

int main(void)
{
	card head;
	card* headptr = &head;
	headptr = (card*)calloc(DECKSIZE, sizeof(card));
	card* current = headptr;
	create_decklist(headptr);
	
	for (int i = 0; i < DECKSIZE; ++i) node_print_debug(headptr + i);

	return 0;
}

// TODO: Find a way to create a linked list from inside a fuction so that it does not need to be initalized in main then populated from the function

//#include "LL Management.c"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc & calloc

#define DECKSIZE 41

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 9, 10 (queen)
	struct card_s* next;
} card;

//void node_append(card* node_end, card* node_new);
void node_create(card* target,  char suit, int face);

void create_decklist(card* head)
{
	head->suit = 'h';
	head->face = 11;
	head->next = head + 1;

	card* current = head + 1;
	for (int i = 1; i <= 40; ++i)
	{
		if (i <= 10) current->suit = 's';
		else if (i <= 20) current->suit = 'd';
		else if (i <= 30) current->suit = 'c';
		else if (i <= 40) current->suit = 'h';
		current->face = (i - 1) % 10;
		current->next = current++;
	}

	return;
}

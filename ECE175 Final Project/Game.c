
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc & calloc

#define DECKSIZE 41
#define SHUFFLES 1000

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 10, 11 (queen)
	struct card_s* next;
} card;

// LL Management.c
card node_create(card* target, char suit, int face);
void node_print_debug(card* target);
void node_print_simple(card* target);
void list_shuffle(card** head);
void array_shuffle(card* array[]);
void content_shuffle(card* head);

// Setup.c
void create_decklist(card* head);

int main(void)
{
	//card head = { 'h', 11, NULL };
	card* headptr = (card*)calloc(DECKSIZE, sizeof(card));

	card* current = headptr;
	create_decklist(current);
	//for (int i = 0; i < DECKSIZE; ++i) node_print_debug(current + i);

	for (int i = 0; i < SHUFFLES; ++i) content_shuffle(headptr);
	for (int i = 0; i < DECKSIZE; ++i) node_print_simple(current + i);

	return 0;
}
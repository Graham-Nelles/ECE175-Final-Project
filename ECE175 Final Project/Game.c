
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
int list_length(card* head);

// Setup.c
void create_decklist(card* head);

// Display.c
void printcard(card target);

int main(void)
{
	card* headptr = (card*)calloc(DECKSIZE, sizeof(card)); // Allocate memory for deck

	create_decklist(headptr);

	//for (int i = 0; i < SHUFFLES; ++i) content_shuffle(headptr); // Shuffle deck SHUFFLES times
	//for (int i = 0; i < DECKSIZE; ++i) node_print_simple(headptr + i); // Print entire deck

	//printf("%d cards long\n", list_length(headptr));
	//printf("\n%d\n", sizeof(card));

	for (int i = 0; i < DECKSIZE; ++i) printcard(*(headptr + i));

	printf("\n%d\n", list_length(headptr));

	return 0;
}
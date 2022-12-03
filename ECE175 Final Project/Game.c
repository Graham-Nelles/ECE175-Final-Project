
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc & calloc
#include <stdbool.h>

#define DECKSIZE 41
#define SHUFFLES 1000

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 10, 11 (queen)
	struct card_s* next;
} card;

typedef struct options_s
{
	int players;
	// Other things here
} options;

// Game.c
void clearpairs(card* head);
void removetwo(card* head, int checkface);

// LL Management.c
card node_create(card* target, char suit, int face);
void node_remove(card* head, card target);
void node_print_debug(card* target);
void node_print_simple(card* target);
void list_shuffle(card** head);
void array_shuffle(card* array[]);
void content_shuffle(card* head);
int list_length(card* head);
bool detectloop(card* head);

// Setup.c
void create_decklist(card* head);
void create_test_list(card* head);
void deal_all(card* deck, card* hand_player, card* hand_bot);

// Menus.c
options menu_main(void);

// Display.c
void printcard(card target);
void printhand(card* head);

int main(void)
{
	//options settings = menu_main();

	card* deckptr = (card*)calloc(DECKSIZE, sizeof(card)); // create ptr and calloc for deck
	card* playerptr = (card*)calloc(1 + DECKSIZE / 2, sizeof(card)); // create ptr and calloc for player hand
	card* botptr = (card*)calloc(DECKSIZE / 2, sizeof(card)); // create ptr and calloc for computer hand
	card* deck_head = deckptr; // Static ptr to head of deck
	card* player_head = playerptr; // Static ptr to head of player hand
	card* bot_head = botptr; // Static ptr to head of bot hand

	create_decklist(deckptr);
	//create_test_list(deckptr);

	for (int i = 0; i < SHUFFLES; ++i) content_shuffle(deckptr); // Shuffle deck SHUFFLES times

	deal_all(deckptr, playerptr, botptr);
	free(deckptr);


	// BOT HAND
	printf("BOT HAND:\n");
	printhand(bot_head);
	clearpairs(bot_head);
	printhand(bot_head);
	printf("\n\n\n");

	// PLAYER HAND
	printf("PLAYER HAND\n");
	printhand(player_head);
	clearpairs(player_head);
	printhand(player_head);

	return 0;
}

void clearpairs(card* head) // Returns 0 if no pairs exist, 1 when pair exists and has been removed
{
	card* curr = head;
	int faces[12] = { 0, 0, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 }; // 0 ignored, each face is stored at index num of that face

	//faces[head->face]++;
	while (curr->next != NULL) // test all elements in list
	{
		faces[curr->face]++;
		curr = curr->next;
	}
	faces[curr->face]++;
	//for (int i = 0; i < 12; ++i) printf("%d\t", faces[i]);
	//printf("\n");

	for (int i = 1; i < 11; ++i) // No need to check for pairs of queens
	{
		if (faces[i] > 1) // Remove first pair
		{
			//printf("%d\n", i);
			//printhand(head);
			removetwo(head, i);
			faces[i] -= 2;
		}
		if (faces[i] > 1) // Remove second pair
		{
			//printf("%d\n", i);
			//printhand(head);
			removetwo(head, i);
			faces[i] -= 2;
		}
	}

	//printf("\n\n\n");
	//printhand(head);

	return;
}

void removetwo(card* head, int checkface)
{
	card imag = { 'a', 0, head }; // Imaginary card becomes head of list within scope of function. Next card is true head of list
	card* imagptr = &imag;

	card* first;
	card* second;
	card* first_prev; // ptr to card before first
	card* second_prev; // ptr to card before second

	// First card
	for (first = imagptr; first->face != checkface; first = first->next); // Save ptr to first card
	//if (first == head) first_prev = imagptr; // first is at head of list, previous is the imag card (UNCOMMENT: Next line is else statement)
	for (first_prev = imagptr; first_prev->next != first; first_prev = first_prev->next); // Iterate first_prev to card before first
	//printf("First card:\n");
	//printcard(*first);

	// Second card
	for (second = first->next; second->face != checkface; second = second->next); // Save ptr to second card
	for (second_prev = head; second_prev->next != second; second_prev = second_prev->next); // Iterate second_prev to card before first
	//printf("Second card:\n");
	//printcard(*second);

	if (second->next == NULL) second_prev->next = NULL; // second is at end of list
	else second_prev->next = second->next; // skip over second
	//printcard(*second_prev);

	if (first_prev == imagptr) *head = *head->next; // first is at head of list
	else first_prev->next = first->next; // skip over first
	//printcard(*first_prev);

	return;
}
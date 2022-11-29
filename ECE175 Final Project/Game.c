
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
bool haspairs(card* head);

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
	// GLOBAL VARS
	int size_playerhand = (DECKSIZE / 2) + 1;
	int size_bothand = DECKSIZE - size_playerhand;

	//options settings = menu_main();

	card* deckptr = (card*)calloc(DECKSIZE, sizeof(card)); // calloc for deck
	card* playerptr = (card*)calloc(1 + DECKSIZE / 2, sizeof(card)); // calloc for player hand
	card* botptr = (card*)calloc(DECKSIZE / 2, sizeof(card)); // calloc for computer hand
	card* deck_head = deckptr;
	card* player_head = playerptr;
	card* bot_head = botptr;

	create_decklist(deckptr);
	//create_test_list(deckptr);

	for (int i = 0; i < SHUFFLES; ++i) content_shuffle(deckptr); // Shuffle deck SHUFFLES times

	/*playerptr->face = deckptr->face;
	playerptr->suit = deckptr->suit;
	playerptr->next = NULL;*/

	deal_all(deckptr, playerptr, botptr);
	printhand(deck_head);
	free(deckptr);
	printhand(player_head);
	printhand(bot_head);

	return 0;
}

bool haspairs(card* head)
{
	bool faces[12] = { 0, 0, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0 }; // 0 ignored, each face is stored at index num of that face
	for (int i = 0; i < list_length(head); ++i) // test all elements in list
	{
		if (faces[head->face] == 1) return 1; // pair found
		else faces[head->face] = 1;
		head = head->next;
	}
	return 0; // no pairs found
}
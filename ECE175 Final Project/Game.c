
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc & calloc
#include <stdbool.h>
#include <string.h>
#include <time.h> // seeding srand

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
bool player_has_queen(card* player_head);
card* card_selection(card* head);
card* card_selection_auto(card* head);

// LL Management.c
card node_create(card* target, char suit, int face);
void node_append(card* head, card* new);
void node_remove(card* head, card target);
void node_print_debug(card* target);
void node_print_simple(card* target);
//void list_shuffle(card** head);
//void array_shuffle(card* array[]);
void content_shuffle(card* head);
void content_shuffle_hand(card* head);
int list_length(card* head);
bool detectloop(card* head);
void node_remove_special(card* head, card* target);

// Setup.c
void create_decklist(card* head);
void create_test_list(card* head);
void deal_all(card* deck, card* hand_player, card* hand_bot);

// Menus.c
options menu_main(void);

// Display.c
void printcard(card target);
void printhand(card* head);
void printblanks(card* head);

int main(void)
{
	srand(time(NULL));
	game_start:

	printf("Welcome to Losing Queen!\n");
	char name[50];
	printf("Enter your name: ");
	fgets(name, 50, stdin);
	*(strchr(name, '\n')) = '\0';
	printf("Welcome, %s!\n", name);

	bool game_end = 0;
	
	card* deckptr = (card*)calloc(DECKSIZE, sizeof(card)); // create ptr and calloc for deck
	card* playerptr = (card*)calloc(1 + DECKSIZE / 2, sizeof(card)); // create ptr and calloc for player hand
	card* botptr = (card*)calloc(1 + DECKSIZE / 2, sizeof(card)); // create ptr and calloc for computer hand
	card* const deck_head = deckptr; // Static ptr to head of deck
	card* const player_head = playerptr; // Static ptr to head of player hand
	card* const bot_head = botptr; // Static ptr to head of bot hand

	create_decklist(deckptr);
	//create_test_list(deckptr);

	for (int i = 0; i < SHUFFLES; ++i) content_shuffle(deckptr); // Shuffle deck SHUFFLES times

	deal_all(deck_head, player_head, bot_head);
	free(deckptr);
	
	// BOT HAND
	printf("\nBOT:\n");
	clearpairs(bot_head);

	// PLAYER HAND
	printf("%s:\n", name);
	clearpairs(player_head);

	bool playerturn;
	if (list_length(player_head) < list_length(bot_head)) playerturn = 1;
	else playerturn = 0;

	card* temp;
	while (!game_end)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		printf("%s's hand:\n", name);
		printhand(player_head);
		printf("Bot hand:\n");
		printblanks(bot_head);

		if (playerturn) // Player's turn
		{
			printf("%s's turn\n", name);
			temp = card_selection(bot_head);
			node_append(player_head, temp);
			node_remove_special(bot_head, temp);
			temp->next = NULL;
		}
		else // Bot's turn
		{
			printf("Bot turn\n");
			temp = card_selection_auto(player_head);
			node_append(bot_head, temp);
			node_remove_special(player_head, temp);
			temp->next = NULL;
		}

		clearpairs(player_head);
		clearpairs(bot_head);

		if (list_length(player_head) == 0)
		{
			printf("%s wins!\n", name);
			game_end = 1;
		}
		else if (list_length(bot_head) == 0)
		{
			printf("Bot wins!\n");
			game_end = 1;
		}

		// Shuffle hands and end turn
		//content_shuffle_hand(player_head);
		//content_shuffle_hand(bot_head);
		playerturn = !playerturn; // Pass turn
	}

	printf("Play again? Y/y to continue.\n");
	char userinp;
	scanf("%c", &userinp);
	if (userinp == 'Y' || userinp == 'y') goto game_start;
	else return 0;
}

void clearpairs(card* head)
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

	// Create temporary list of two cards to use printhand to print what cards were removed
	card secondremoved;
	card firstremoved;

	// First card
	for (first = imagptr; first->face != checkface; first = first->next); // Save ptr to first card
	//if (first == head) first_prev = imagptr; // first is at head of list, previous is the imag card (UNCOMMENT: Next line is else statement)
	for (first_prev = imagptr; first_prev->next != first; first_prev = first_prev->next); // Iterate first_prev to card before first
	//printf("First card:\n");
	//printcard(*first);
	firstremoved.face = first->face;
	firstremoved.suit = first->suit;

	// Second card
	for (second = first->next; second->face != checkface; second = second->next); // Save ptr to second card
	for (second_prev = head; second_prev->next != second; second_prev = second_prev->next); // Iterate second_prev to card before first
	//printf("Second card:\n");
	//printcard(*second);
	secondremoved.face = second->face;
	secondremoved.suit = second->suit;

	if (second->next == NULL) second_prev->next = NULL; // second is at end of list
	else second_prev->next = second->next; // skip over second
	//printcard(*second_prev);

	if (first_prev == imagptr) *head = *head->next; // first is at head of list
	else first_prev->next = first->next; // skip over first
	//printcard(*first_prev);

	firstremoved.next = &secondremoved;
	secondremoved.next = NULL;
	printf("Removing pair:\n");
	printhand(&firstremoved);
	
	return;
}

bool player_has_queen(card* player_head)
{
	for (card* current = player_head; current->next != NULL; current = current->next)
	{
		if (current->face == 11) return 1; // Player has queen
	}
	return 0; // Player does not have queen
}

card* card_selection(card* head)
{
	card* current = head;
	int cards = list_length(head);

	for (int i = 1; i <= cards; ++i) printf("%d\t", i); // Print number for each card that can be selected

	int selection = 0;
	while (selection <= 0 || selection > cards)
	{
		printf("\nEnter a number between 1 and %d to select a card: ", cards);
		scanf("%d", &selection);
	}
	printf("You selected card #%d\n\n", selection);

	if (selection != 1) for (int i = 1; i < selection; ++i)
	{
		current = current->next;
	}
	/*
	card* temp = current;

	if (selection == 1)// First card in list
	{
		head->face = head->next->face;
		head->suit = head->next->suit;
		head->next = head->next->next;
	}
	else if (selection == cards) node_remove_special(head, current, 3); // Last card in list
	else node_remove_special(head, current, 2); // Card in middle of list
	*/
	return current;
}

card* card_selection_auto(card* head)
{
	card* current = head;
	int cards = list_length(head);

	int selection = (rand() % list_length(head)) + 1;
	printf("Bot has selected card #%d\n", selection);

	if (selection != 1) for (int i = 1; i < selection; ++i)
	{
		current = current->next;
	}
	/*
	card* temp = current;

	if (selection == 1)// First card in list
	{
		head->face = head->next->face;
		head->suit = head->next->suit;
		head->next = head->next->next;
	}
	else if (selection == cards) node_remove_special(head, current, 3); // Last card in list
	else node_remove_special(head, current, 2); // Card in middle of list
	*/
	return current;
}
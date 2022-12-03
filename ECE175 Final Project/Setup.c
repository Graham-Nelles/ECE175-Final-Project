
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
void node_remove(card* head, card target);
void node_print_debug(card* target);
int list_length(card* head);

void create_decklist(card* head)
{
	head->suit = 'h';
	head->face = 11;
	head->next = head + 1;

	card* current = head + 1;
	for (int i = 1; i <= 10; ++i) // Create spades
	{
		current->suit = 's';
		current->face = i;
		current->next = current + 1;
		current = current->next;
	}
	for (int i = 1; i <= 10; ++i) // Create diamonds
	{
		current->suit = 'd';
		current->face = i;
		current->next = current + 1;
		current = current->next;
	}
	for (int i = 1; i <= 10; ++i) // Create clubs
	{
		current->suit = 'c';
		current->face = i;
		current->next = current + 1;
		current = current->next;
	}
	for (int i = 1; i <= 9; ++i) // Create hearts except 10
	{
		current->suit = 'h';
		current->face = i;
		current->next = current + 1;
		current = current->next;
	}
	current->suit = 'h';
	current->face = 10;
	current->next = NULL; // End list

	return;
}

void deal_all(card* deck, card* hand_player, card* hand_bot)
{
	card* deckptr = deck;
	card* playerptr = hand_player;
	card* botptr = hand_bot;

	while (1)
	{

		if (deckptr->next == NULL)
		{
			playerptr->face = deckptr->face;
			playerptr->suit = deckptr->suit;
			playerptr->next = NULL;
			(botptr - 1)->next = NULL;
			return;
		}
		else
		{
			playerptr->face = deckptr->face;
			playerptr->suit = deckptr->suit;
			playerptr->next = playerptr + 1;
			playerptr = playerptr->next;
			deckptr = deckptr->next;
		}

		if (deckptr->next == NULL)
		{
			botptr->face = deckptr->face;
			botptr->suit = deckptr->suit;
			botptr->next = NULL;
			(playerptr - 1)->next = NULL;
			return;
		}
		else
		{
			botptr->face = deckptr->face;
			botptr->suit = deckptr->suit;
			botptr->next = botptr + 1;
			botptr = botptr->next;
			deckptr = deckptr->next;
		}
	}

	return;
}

void create_test_list(card* head)
{
	head->suit = 'h';
	head->face = 11;
	head->next = head + 1;

	card* current = head + 1;
	for (int i = 3; i <= 9; ++i) // Create hearts except 10
	{
		current->suit = 'h';
		current->face = i;
		current->next = current + 1;
		current = current->next;
	}

	// Extra 10 to create a pair
	current->suit = 's';
	current->face = 10;
	current->next = current + 1;
	current = current->next;

	current->suit = 'h';
	current->face = 10;
	current->next = NULL; // End list

	return;
}
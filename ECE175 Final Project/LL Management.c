// This file includes all functions for handling linked lists

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand, srand

#define DECKSIZE 41
#define SEED 1 // Seed for rand
#define HEARTS 3
#define DIAMONDS 4
#define CLUBS 5
#define SPADES 6

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 9, 10 (queen)
	struct card_s* next;
} card;

void node_create(card* target, char suit, int face)
{
	target->suit = suit;
	target->face = face;
}

/*void node_append(card* node_end, card* node_new)
{
	node_end->next = node_new;
	return;
}*/

void node_insert(card* node_before, card* node_new, card* node_after)
{
	node_before->next = node_new;
	node_new->next = node_after;
	return;
}

void node_remove(card* head, card* target)
{
	card* temp = head;
	if (head == target) head = target; // Remove first element of list
	else for (int i = 0; i < DECKSIZE; ++i) if (temp->next == target) temp->next = target->next; // Once found, make node before target point to node after target
	return;
}

void node_print_debug(card* target)
{
	printf("%d of %c, next is %p\n", target->face, target->suit, target->next);
	return;
}

void node_print_simple(card* target)
{
	if (target->face == 11) // Queen of hearts
	{
		printf("Queen of %c\n", HEARTS);
		return;
	}

	char printsuit;
	if (target->suit == 's') printsuit = SPADES;
	else if (target->suit == 'h') printsuit = HEARTS;
	else if (target->suit == 'c') printsuit = CLUBS;
	else printsuit = DIAMONDS;

	printf("%d of %c\n", target->face, printsuit);
	return;
}

void content_shuffle(card* head) // Currently working shuffle function
{
	// This function works by keeping the list structure itself unchanged, swapping the contents of cards to shuffle the deck
	
	// Temp vars for holding card info during swap
	char suit_temp;
	int face_temp;

	int target_ind;
	card* target;
	card* current;
	for (int i = 0; i < DECKSIZE; ++i)
	{
		current = head + i; // Ptr to first card to be swapped

		target_ind = rand() % DECKSIZE;
		target = head + target_ind; // Ptr to second card to be swapped

		suit_temp = current->suit;
		face_temp = current->face;

		current->suit = target->suit;
		current->face = target->face;

		target->suit = suit_temp;
		target->face = face_temp;

		/*printf("Swap #%d- Swapped cards:\n", i);
		printf("Current: ");
		node_print_simple(current);
		printf("Target: ");
		node_print_simple(target);
		printf("\n\n");*/
	}
	return;
}

// OLD SHUFFLE FUNCTIONS

void list_shuffle(card** head)
{
	// Create listarr
	card* head_old = *head;
	card* listarr[DECKSIZE];
	for (int i = 0; i < DECKSIZE; ++i) listarr[i] = head_old + i;

	// Shuffle listarr
	srand(SEED);
	card* temp;
	int swapind;
	for (int i = 0; i < DECKSIZE; ++i)
	{
		swapind = rand() % DECKSIZE;
		temp = listarr[i];
		listarr[i] = listarr[swapind];
		listarr[swapind] = temp;
	}

	// Relink cards in listarr
	for (int i = 0; i < DECKSIZE - 1; ++i) listarr[i]->next = listarr[i + 1]; // Relink all cards except last
	listarr[DECKSIZE - 1]->next = NULL; // Termainate list at last element

	// Output shuffled list

}

void list_to_array(card* head, card** array)
{
	for (int i = 0; i < DECKSIZE; ++i)
	{
		array[i] = head;
		head++;
	}
	return;
}

void array_shuffle(card* array[])
{
	srand(SEED);
	card* temp;
	for (int i = 0; i < 1000; ++i) // 1000 shuffles
	{
		for (int j = 0; j < DECKSIZE; ++j)
		{
			int swapind = rand() % DECKSIZE;
			temp = array[j];
			array[j] = array[swapind];
			array[swapind] = temp;
		}
	}
}
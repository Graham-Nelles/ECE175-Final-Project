// This file includes all functions for handling linked lists

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <stdbool.h>

#define DECKSIZE 41 // Number of cards in deck
#define SEED 1 // Seed for rand - normally seeded with time()
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

void node_transfer(card* list_donor, card* list_reciever, card* target) // This function might actually need 3 args: head of donor list, head of reciever list, node to be transferred from donor to reciever
{
	// FIXME: this will likely rely rely on node_remove. Validate node_remove before proceeding with this function
}

void node_append(card* head, card* new)
{
	card* current;
	for (current = head; current->next != NULL; current = current->next);
	current->next = new;
	new->next = NULL;

	return;
}

void node_insert(card* node_before, card* node_new, card* node_after)
{
	node_before->next = node_new;
	node_new->next = node_after;
	return;
}

void node_remove(card* head, card target) // FIXME: not finding target card, returning same list
{
	if (head->face == target.face && head->suit == target.suit) // Remove first card of list
	{
		head = &target;
		return;
	}

	card* temp;
	card* tempnext;
	for (int i = 0; i < list_length(head) - 1; ++i)
	{
		temp = head + i;
		tempnext = temp->next;
		if (tempnext->face == target.face && tempnext->suit == target.suit)
		{
			temp = tempnext->next;
			return;
		}
	}

	printf("Error: card not found\n");
	return;
}

void node_print_debug(card* target)
{
	printf("card at %p is %d of %c, next is %p\n", target, target->face, target->suit, target->next);
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
	
	int size = list_length(head);
	srand(SEED);

	// Temp vars for holding card info during swap
	char suit_temp;
	int face_temp;

	int target_ind;
	card* target;
	card* current;
	for (int i = 0; i < size; ++i)
	{
		current = head + i; // Ptr to first card to be swapped

		target_ind = rand() % size;
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

int list_length(card* head)
{
	int cards = 0;
	card* current = head;
	if (current == NULL) return cards;
	while (current != NULL)
	{
		cards++; // Increment counter
		//node_print_simple(current);
		current = current->next; // Go to next card
	}
	return cards;
}

bool detectloop(card* head)
{
	// Tortise and hare algorithm

	card* tortise = head; // Slow
	card* hare = head; // Fast

	while (1)
	{
		tortise = tortise->next; // Move to next node
		hare = hare->next->next; // Move two nodes after current

		if (hare->next == NULL || hare->next->next == NULL) return 0; // hare has reached end of list
		if (tortise == hare) return 1; // hare has caught up to tortise
	}
}

// OLD SHUFFLE FUNCTIONS - IGNORE BELOW HERE

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
	return;
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

void node_remove_special(card* head, card* target, int type)
{
	// TYPES:
	// 1: beginning of list
	// 2: middle of list
	// 3: end of list

	card* current;
	
	switch (type)
	{
	case 1:
		head->face = head->next->face;
		head->suit = head->next->suit;
		head->next = head->next->next;
		return;
	case 2:
		for (current = head; current->next != target; current = current->next); // Iterate to card before target
		current->next = target->next;
		return;
	case 3:
		for (current = head; current->next != target; current = current->next); // Iterate to card before target
		current->next = NULL;
		return;
	default:
		printf("Error: Invalid type\n");
		return;
	}
}
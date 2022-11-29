
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define HEARTS 3
#define DIAMONDS 4
#define CLUBS 5
#define SPADES 6

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 10, 11 (queen)
	struct card_s* next;
} card;

// LL Managment.c
int list_length(card* head);

void printhand(card* head)
{
	int cards = list_length(head);

	// Top edges
	for (int i = 0; i < cards; ++i)
	{
		printf("%c", 2522);
		for (int i = 0; i < 9; ++i)	printf("%c", 2500);
		printf("%c  ", 2495);
	}
	printf("\n");

	// Upper sides
	for (int i = 0; i < cards; ++i) printf("%c         %c  ", 2483, 2483);
	printf("\n");
	for (int i = 0; i < cards; ++i) printf("%c         %c  ", 2483, 2483);
	printf("\n");

	// Center sides
	
	for (int i = 0; i < cards; ++i)
	{
		if (head->suit == 'h')	printf("%c   %c ", 2483, HEARTS);
		else if (head->suit == 'd')	printf("%c   %c ", 2483, DIAMONDS);
		else if (head->suit == 'c')	printf("%c   %c ", 2483, CLUBS);
		else if (head->suit == 's')	printf("%c   %c ", 2483, SPADES);
		else printf("ERROR: invalid suit\n");

		if (head->face == 1) printf("%c   %c  ", 'A', 2483); // Aces
		else if (head->face == 10) printf("%d  %c  ", head->face, 2483); // One less space after face for 10
		else if (head->face == 11) printf("%c   %c  ", 'Q', 2483); // Queen
		else printf("%d   %c  ", head->face, 2483);

		head = head->next;
	}
	printf("\n");

	// Lower sides
	for (int i = 0; i < cards; ++i) printf("%c         %c  ", 2483, 2483);
	printf("\n");
	for (int i = 0; i < cards; ++i) printf("%c         %c  ", 2483, 2483);
	printf("\n");

	// Bottom edges
	for (int i = 0; i < cards; ++i)
	{
		printf("%c", 2496);
		for (int i = 0; i < 9; ++i)	printf("%c", 2500);
		printf("%c  ", 2521);
	}
	printf("\n");

	return;
}

void printcard(card target)
{
	printf("%c", 2522);
	for (int i = 0; i < 9; ++i)	printf("%c", 2500);
	printf("%c\n", 2495);
	for (int i = 0; i < 2; ++i) printf("%c         %c\n", 2483, 2483);

	if (target.suit == 'h')	printf("%c   %c ", 2483, HEARTS);
	else if (target.suit == 'd')	printf("%c   %c ", 2483, DIAMONDS);
	else if (target.suit == 'c')	printf("%c   %c ", 2483, CLUBS);
	else if (target.suit == 's')	printf("%c   %c ", 2483, SPADES);
	else printf("ERROR: invalid suit\n");

	if (target.face == 1) printf("%c   %c\n", 'A', 2483); // Aces
	else if (target.face == 10) printf("%d  %c\n", target.face, 2483); // One less space after face for 10
	else if (target.face == 11) printf("%c   %c\n", 'Q', 2483); // Queen
	else printf("%d   %c\n", target.face, 2483);

	for (int i = 0; i < 2; ++i) printf("%c         %c\n", 2483, 2483);
	printf("%c", 2496);
	for (int i = 0; i < 9; ++i)	printf("%c", 2500);
	printf("%c\n", 2521);

	return;
}
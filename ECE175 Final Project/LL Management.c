// This file includes all functions for handling linked lists

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct card_s
{
	char suit; // s (spade), d (diamond), c (club), h (heart)
	int face; // 1 (ace) - 9, 10 (queen)
	struct card_s* next;
} card;

card node_create(char suit, int face)
{
	card new;
	new.suit = suit;
	new.face = face;
	return new;
}

void node_append(card* node_end, card* node_new)
{
	node_end->next = node_new;
	return;
}

void node_insert(card* node_before, card* node_new, card* node_after)
{
	node_before->next = node_new;
	node_new->next = node_after;
	return;
}

void node_print_debug(card target)
{
	printf("%d of %c, next is %.8X\n", target.face, target.suit, (unsigned)target.next);
	return;
}
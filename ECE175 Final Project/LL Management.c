// This file includes all functions for handling linked lists

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct card_s
{
	char suit;
	int face;
	struct card_s* next;
} card;


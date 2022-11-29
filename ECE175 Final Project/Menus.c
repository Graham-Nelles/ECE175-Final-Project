
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct options_s
{
	int players;
	// Other things here
} options;

options menu_main(void)
{
	options settings = { 1 };

	printf("Graham S. Nelles\n");
	printf("ECE175 Final Project\n");
	printf("Losing Queen\n");
	printf("\n");
	printf("0: Start game\n");
	printf("Make a selection: ");
	// Finish adding options

	int userinp;
	scanf("%d", &userinp);
	switch (userinp)
	{
	case 0:
		return settings; // Leave function and start game
	}
}
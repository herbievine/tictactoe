/**
 * @file logger.c
 * @author Herbie Vine (vineherbie@gmail.com)
 * @version 1.0
 * @date 2022-06-28
 *
 * @copyright MIT License. See LICENSE file in the project root for full license information.
 *
 */

#include <stdio.h>

void display_board(char board[9])
{
	printf(" %c | %c | %c\n", board[0], board[1], board[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[3], board[4], board[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

void display_winner(char winner, char player)
{
	if (winner == 't')
	{
		printf("*****************\n");
		printf("*** You tied! ***\n");
		printf("*****************\n");
	}
	else if (winner == player)
	{
		printf("****************\n");
		printf("*** You won! ***\n");
		printf("****************\n");
	}
	else if (winner != player)
	{
		printf("*****************\n");
		printf("*** You lost! ***\n");
		printf("*****************\n");
	}
}
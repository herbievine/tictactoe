/**
 * @file board.c
 * @author Herbie Vine (vineherbie@gmail.com)
 * @version 1.0
 * @date 2022-06-28
 *
 * @copyright MIT License. See LICENSE file in the project root for full license information.
 *
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#include "board.h"
#include "minimax.h"

void init_board(char board[9], char empty)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = empty;
	}
}

int check_free_spaces(char board[9])
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			count++;
		}
	}

	return count;
}

char choose_player()
{
	char player_choice;

	printf("Do you want to play as 'x' or 'o'?\n");
	scanf("%c", &player_choice);

	while (player_choice != 'x' && player_choice != 'o')
	{
		printf("Invalid input. Do you want to play as 'x' or 'o'?\n");
		scanf("%c", &player_choice);
	}

	return player_choice;
}

void player_turn(char board[9], char player)
{
	printf("%c's turn.\n", player);

	int pos;

	printf("Enter the position of the square you want to mark.\n");
	scanf("%d", &pos);

	while (board[pos - 1] != ' ')
	{
		printf("Invalid input. Enter the position of the square you want to mark.\n");
		scanf("%d", &pos);
	}

	board[pos - 1] = player;
}

void computer_turn(char board[9], char computer)
{
	printf("%c's turn.\n", computer);

	int best_score = INT_MIN;
	int best_pos = -1;
	int free_spaces = check_free_spaces(board);

	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			if (free_spaces == 1)
			{
				best_pos = i;
			}
			else
			{
				board[i] = computer;

				int score = minimax(board, 0, 10, false, computer);

				board[i] = ' ';

				if (score > best_score)
				{
					best_score = score;
					best_pos = i;
				}
			}
		}
	}

	board[best_pos] = computer;
}

char check_winner(char board[9])
{
	int wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

	for (int i = 0; i < 8; i++)
	{
		if (board[wins[i][0]] != ' ' &&
				board[wins[i][0]] == board[wins[i][1]] &&
				board[wins[i][1]] == board[wins[i][2]])
		{
			return board[wins[i][2]];
		}
	}

	return ' ';
}

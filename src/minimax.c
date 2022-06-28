/**
 * @file minimax.c
 * @author Herbie Vine (vineherbie@gmail.com)
 * @version 1.0
 * @date 2022-06-28
 *
 * @copyright MIT License. See LICENSE file in the project root for full license information.
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "minimax.h"
#include "board.h"

int minimax(char board[9], int depth, int max_depth, bool is_maximizing, char computer)
{
	char winner = check_winner(board);
	int free_spaces = check_free_spaces(board);
	char player = computer == 'x' ? 'o' : 'x';

	if (free_spaces <= 1)
		return 0;
	else if (winner == computer)
		return 1;
	else if (winner == player)
		return -1;

	if (is_maximizing)
	{
		int best_score = INT_MIN;

		for (int i = 0; i < 9; i++)
		{
			if (board[i] == ' ')
			{
				board[i] = computer;

				int score = minimax(board, depth + 1, max_depth, false, computer);

				board[i] = ' ';

				if (score > best_score)
				{
					best_score = score;
				}
			}
		}

		return best_score;
	}
	else
	{
		int best_score = INT_MAX;

		for (int i = 0; i < 9; i++)
		{
			if (board[i] == ' ')
			{
				board[i] = player;

				int score = minimax(board, depth + 1, max_depth, true, computer);

				board[i] = ' ';

				if (score < best_score)
				{
					best_score = score;
				}
			}
		}

		return best_score;
	}
}
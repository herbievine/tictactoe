/**
 * @file main.c
 * @author Herbie Vine (vineherbie@gmail.com)
 * @version 1.0
 * @date 2022-06-28
 *
 * @copyright MIT License. See LICENSE file in the project root for full license information.
 *
 */

#include <stdio.h>
#include <stdbool.h>

#include "board.h"
#include "logger.h"

int main()
{
	char board[9];
	char player;
	char computer;
	char next_turn = 'x';
	const char EMPTY = ' ';
	const char TIE = 't';
	char winner = ' ';
	int free_spaces = check_free_spaces(board);

	init_board(board, EMPTY);

	player = choose_player();
	computer = (player == 'x') ? 'o' : 'x';

	while (winner == ' ')
	{
		display_board(board);

		if (next_turn == player)
		{
			player_turn(board, player);

			free_spaces = check_free_spaces(board);

			winner = check_winner(board);

			if (free_spaces == 0)
			{
				winner = TIE;
			}

			next_turn = computer;
		}
		else
		{
			computer_turn(board, computer);

			free_spaces = check_free_spaces(board);

			winner = check_winner(board);

			if (free_spaces == 0)
			{
				winner = TIE;
			}

			next_turn = player;
		}
	}

	display_winner(winner, player);
	display_board(board);

	return 0;
}
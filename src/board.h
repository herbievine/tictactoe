#ifndef BOARD_H
#define BOARD_H

void init_board(char board[9], char empty);
int check_free_spaces(char board[9]);
char choose_player();
void player_turn(char board[9], char player);
void computer_turn(char board[9], char computer);
char check_winner(char board[9]);

#endif
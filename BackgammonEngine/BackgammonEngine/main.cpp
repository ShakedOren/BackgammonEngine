#include <iostream>

#include "Board.h"

int main()
{
	Backgammon::Board board;
	board.print_board();
	board.move_white_chip(0, 2);
	board.move_black_chip(0, 3);
	board.print_board();
	return 0;
}
#include <iostream>

#include "Board.h"

int main()
{
	Backgammon::Board board;
	board.print_board();
	std::cout << "------------" << std::endl;
	board.get_player1().move_chip(0, 3);
	board.get_player2().move_chip(0, 2);
	board.print_board();

	return 0;
}
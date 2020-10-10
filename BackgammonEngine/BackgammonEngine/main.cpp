#include <iostream>

#include "Board.h"

int main()
{
	Backgammon::Board board;
	board.print_board();
	std::cout << "------------" << std::endl;
	board.move_chip(0,0, 3);
	board.move_chip(1,0, 2);
	board.print_board();

	return 0;
}
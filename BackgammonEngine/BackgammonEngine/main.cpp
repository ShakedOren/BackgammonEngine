#include <iostream>

#include "Board.h"

int main()
{
	Backgammon::Board board;
	board.print_board();
	std::cout << "------------" << std::endl;
	board.move_chip(Backgammon::Board::PlayerId::PLAYER1, 0, 3);
	board.move_chip(Backgammon::Board::PlayerId::PLAYER2, 0, 2);
	board.move_chip(Backgammon::Board::PlayerId::PLAYER2, 0, 5);
	board.print_board();

	return 0;
}
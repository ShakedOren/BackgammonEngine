#include "Board.h"

namespace Backgammon
{

Board::Board()
	: board_(NUM_OF_POINTS_ON_BOARD)
{
	init_board<>(board_.begin(), Chip::Color::WHITE);
	init_board<>(board_.rbegin(), Chip::Color::BLACK);
}

void Board::print_board()
{
	int curr_num_of_chips_on_point = 0;
	for (const auto& point : board_)
	{
		point.print_point();	
	}

	std::cout << std::endl;
}

void Board::move_white_chip(int start_pos, int end_pos)
{
	move_chip(board_.begin(), start_pos, end_pos, Chip::Color::WHITE);
}

void Board::move_black_chip(int start_pos, int end_pos)
{
	move_chip(board_.rbegin(), start_pos, end_pos, Chip::Color::BLACK);
}

} // namespace Backgammon

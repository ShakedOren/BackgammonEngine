#include "Board.h"

namespace Backgammon
{

Board::Board()
	: board_(NUM_OF_POINTS_ON_BOARD)
{
	init_white_points();
	init_black_points();
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

void Board::init_white_points()
{
	auto chip_color = Chip::Color::WHITE;
	auto board_start = board_.begin();

	board_start->set_num_of_chips_on_point(2, chip_color);
	(board_start + 11)->set_num_of_chips_on_point(5, chip_color);
	(board_start + 16)->set_num_of_chips_on_point(3, chip_color);
	(board_start + 18)->set_num_of_chips_on_point(5, chip_color);
}

void Board::init_black_points()
{
	auto chip_color = Chip::Color::BLACK;
	auto board_start = board_.rbegin();

	board_start->set_num_of_chips_on_point(2, chip_color);
	(board_start + 11)->set_num_of_chips_on_point(5, chip_color);
	(board_start + 16)->set_num_of_chips_on_point(3, chip_color);
	(board_start + 18)->set_num_of_chips_on_point(5, chip_color);
}
void Board::move_white_chip(int start_pos, int end_pos)
{
	auto chip_color = Chip::Color::WHITE;
	auto board_start = board_.begin();

	(board_start + start_pos)->remove_last_chip();
	(board_start + end_pos)->add_chip(chip_color);
}

void Board::move_black_chip(int start_pos, int end_pos)
{
	auto chip_color = Chip::Color::BLACK;
	auto board_start = board_.rbegin();

	(board_start + start_pos)->remove_last_chip();
	(board_start + end_pos)->add_chip(chip_color);
}

} // namespace Backgammon

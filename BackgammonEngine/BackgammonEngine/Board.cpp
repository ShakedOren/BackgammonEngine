#include "Board.h"

namespace Backgammon
{

Board::Board()
	: board_(NUM_OF_POINTS_ON_BOARD)
{

}

void Board::init_white_points()
{
	init_points(board_.begin(), Chip::Color::WHITE);
}

void Board::init_black_points()
{
	init_points(board_.rbegin(), Chip::Color::BLACK);
}

void Board::init_points(std::vector<Point>::iterator board_start, Chip::Color chip_color)
{
	board_start->set_num_of_chips_on_point(2, chip_color);
	(board_start+11)->set_num_of_chips_on_point(5, chip_color);
	(board_start+16)->set_num_of_chips_on_point(3, chip_color);
	(board_start+18)->set_num_of_chips_on_point(5, chip_color);
}

void Board::init_points(std::vector<Point>::reverse_iterator board_start, Chip::Color chip_color)
{
	board_start->set_num_of_chips_on_point(2, chip_color);
	(board_start + 11)->set_num_of_chips_on_point(5, chip_color);
	(board_start + 16)->set_num_of_chips_on_point(3, chip_color);
	(board_start + 18)->set_num_of_chips_on_point(5, chip_color);
}
} // namespace Backgammon

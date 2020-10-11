#pragma once

#include <iostream>

#include "Points.h"

namespace Backgammon
{

class Board
{
public:
	static constexpr int NUM_OF_POINTS_ON_BOARD = 24;

public:
	Board();

	void print_board();
	void move_white_chip(int start_pos, int end_pos);
	void move_black_chip(int start_pos, int end_pos);

private:
	std::vector<Point> board_;
};

template <class T>
void init_board(T board_start, Chip::Color chip_color)
{
	board_start->set_num_of_chips_on_point(2, chip_color);
	(board_start + 11)->set_num_of_chips_on_point(5, chip_color);
	(board_start + 16)->set_num_of_chips_on_point(3, chip_color);
	(board_start + 18)->set_num_of_chips_on_point(5, chip_color);
}

template <class T>
void move_chip(T board_start, int start_pos, int end_pos, Chip::Color chip_color)
{
	(board_start + start_pos)->remove_last_chip();
	(board_start + end_pos)->add_chip(chip_color);
}

template <class T>
bool check_move_valid(T board_start, int start_pos, int end_pos, Chip::Color chip_color)
{
	if (board_start + start_pos)->check_if_point_empty())
	{
		return false;
	}

	return true;
}

} // namespace Backgammon


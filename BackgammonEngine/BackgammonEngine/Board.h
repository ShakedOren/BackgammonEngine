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
	enum class PlayerChipsColor
	{
		WHITE = 0,
		BLACK = 1,
	};

public:
	Board();

	void print_board();

private:
	std::vector<Point> board_;

private:
	void init_white_points();
	void init_black_points();
	void init_points(std::vector<Point>::iterator board_start, Chip::Color chip_color);
	void init_points(std::vector<Point>::reverse_iterator board_start, Chip::Color chip_color);
};	

} // namespace Backgammon


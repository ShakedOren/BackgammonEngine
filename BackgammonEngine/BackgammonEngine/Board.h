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
	void move_white_chip(int start_pos, int end_pos);
	void move_black_chip(int start_pos, int end_pos);

private:
	std::vector<Point> board_;

private:
	void init_white_points();
	void init_black_points();
};	

} // namespace Backgammon


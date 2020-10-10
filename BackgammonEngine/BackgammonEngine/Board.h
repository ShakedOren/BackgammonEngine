#pragma once

#include "Player.h"

#include <iostream>

namespace Backgammon
{

class Board
{
public:
	Board() : player1_(Chip::Color::WHITE), player2_(Chip::Color::BLACK) {};
	
	Player& get_player1() { return player1_; };
	Player& get_player2() { return player2_; };

	void print_board();
	void move_chip(int src_point, int dst_point);

	
private:
	Player player1_;
	Player player2_;

private:
	std::vector<Point> get_full_board();

};

} // namespace Backgammon


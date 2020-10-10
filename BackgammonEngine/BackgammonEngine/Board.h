#pragma once

#include "Player.h"

#include <iostream>

namespace Backgammon
{

class Board
{
public:
	Board() = default;
	
	void print_board();
	Player& get_player1() { return player1_; };
	Player& get_player2() { return player2_; };

private:
	Player player1_;
	Player player2_;

private:
	std::vector<Point> get_full_board();

};

} // namespace Backgammon


#pragma once

#include "Player.h"

#include <iostream>

namespace Backgammon
{

class Board
{
public:
	Board();
	
	Player& get_player(int player_id);

	void print_board();
	void move_chip(int player_id, int src_point, int dst_point);

	
private:
	std::vector<Player> players_;

private:
	std::vector<Point> get_full_board();

};

} // namespace Backgammon


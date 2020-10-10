#pragma once

#include "Player.h"

#include <iostream>

namespace Backgammon
{

class Board
{
public:
	enum class PlayerId
	{
		PLAYER1 = 0,
		PLAYER2 = 1,
	};
public:
	Board();
	
	Player& get_player(PlayerId player_id);

	void print_board();
	void move_chip(PlayerId player_id, int src_point, int dst_point);

	
private:
	std::vector<Player> players_;

private:
	std::vector<Point> get_full_board();
	bool check_if_move_valid(PlayerId player_id, int src_point, int dst_point);
	bool check_if_point_is_empty(PlayerId player_id, int point_id);
	PlayerId get_other_player_id(PlayerId player_id);
	int pos_from_end_to_pos_from_start(int point_id_from_end);
};

} // namespace Backgammon


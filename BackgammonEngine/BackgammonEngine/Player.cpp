#include "Player.h"

namespace Backgammon
{
Player::Player(Chip::Color player_color)
	: points_(NUM_OF_POINTS), player_color_(player_color)
{
	init_points();
}

void Player::init_points()
{
	points_[0].set_num_of_chips_on_point(2, player_color_);
	points_[11].set_num_of_chips_on_point(5, player_color_);
	points_[16].set_num_of_chips_on_point(3, player_color_);
	points_[18].set_num_of_chips_on_point(5, player_color_);
}

void Player::move_chip(int src_point, int dst_point)
{
	points_[src_point].remove_last_chip();
	points_[dst_point].add_chip(player_color_);
}

} // namespace Backgammon
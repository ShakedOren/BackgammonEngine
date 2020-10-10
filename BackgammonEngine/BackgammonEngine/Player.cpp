#include "Player.h"

namespace Backgammon
{
Player::Player()
	: points_(NUM_OF_POINTS)
{
	init_points();
}

void Player::init_points()
{
	points_[0].set_num_of_chips_on_point(2);
	points_[11].set_num_of_chips_on_point(5);
	points_[16].set_num_of_chips_on_point(3);
	points_[18].set_num_of_chips_on_point(5);
}

void Player::move_chip(int src_point, int dst_point)
{
	points_[src_point].remove_chip();
	points_[dst_point].add_chip();
}

} // namespace Backgammon
#pragma once

#include <vector>

#include "Points.h"

namespace Backgammon
{

class Player
{
public:
	static constexpr int NUM_OF_POINTS = 24;

public:
	Player(Chip::Color player_color);

	std::vector<Point> get_points() { return points_; };
	void move_chip(int src_point, int dst_point);

private:
	std::vector<Point> points_;
	Chip::Color player_color_;

private:
	void init_points();
};

} // namespace Backgammon
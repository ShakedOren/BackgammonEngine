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
	Player();

	std::vector<Point> get_points_() { return points_; };
	void move_chip(int src_point, int dst_point);

private:
	std::vector<Point> points_;

private:
	void init_points();
};

} // namespace Backgammon
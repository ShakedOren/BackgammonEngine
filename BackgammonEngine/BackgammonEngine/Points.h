#pragma once

#include <vector>

#include "Chip.h"

namespace Backgammon
{

class Point
{
public:
	Point() = default;
	
	void set_num_of_chips_on_point(int num_of_chips_on_point, Chip::Color chips_color);
	int get_num_of_chips_on_point() { return chips_on_point_.size(); };

	void add_chip(Chip::Color chip_color);
	void remove_last_chip();

private:
	std::vector<Chip> chips_on_point_;
};

} // namespace Backgammon


#include "Points.h"

namespace Backgammon
{

void Point::set_num_of_chips_on_point(int num_of_chips_on_point, Chip::Color chips_color)
{
	for (size_t i = 0; i < num_of_chips_on_point; i++)
	{
		chips_on_point_.emplace_back(chips_color);
	}
}

void Point::add_chip(Chip::Color chip_color)
{
	chips_on_point_.emplace_back(chip_color);
}

void Point::remove_last_chip()
{
	if (chips_on_point_.empty())
	{

	}

	chips_on_point_.pop_back();
}


} // namespace Backgammon

#include "Points.h"

#include <exception>
#include <iostream>

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
	if (check_if_point_empty())
	{
		throw std::exception("Can't remove chip, point in empty");
	}

	chips_on_point_.pop_back();
}

bool Point::check_if_point_empty() const
{ 
	return chips_on_point_.empty(); 
}

Chip::Color Point::get_first_chip_color() const
{
	if (check_if_point_empty())
	{
		throw std::exception("Can't get first chip color, point in empty");
	}

	return chips_on_point_[0].get_chip_color();
}

void Point::print_point() const
{
	if (!check_if_point_empty())
	{
		auto str_color = get_first_chip_color() == Chip::Color::WHITE ? "W:" : "B:";
		std::cout << str_color;
	}
	std::cout << get_num_of_chips_on_point() << " ";
}

} // namespace Backgammon

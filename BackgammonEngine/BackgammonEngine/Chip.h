#pragma once

namespace Backgammon
{

class Chip
{
public:
	enum class Color
	{
		WHITE,
		BLACK
	};

public:
	Chip(Color chip_color) : chip_color_(chip_color) {};
	
	Color get_chip_color() const { return chip_color_; };

private:
	Color chip_color_;
};

} // namespace Backgammon



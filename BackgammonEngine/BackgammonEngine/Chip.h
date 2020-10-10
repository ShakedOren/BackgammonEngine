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

private:
	Color chip_color_;
};

} // namespace Backgammon


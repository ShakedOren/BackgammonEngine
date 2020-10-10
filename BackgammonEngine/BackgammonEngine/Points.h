#pragma once

namespace Backgammon
{

class Point
{
public:
	Point() = default;
	
	void set_num_of_chips_on_point(int num_of_chips_on_point) { num_of_chips_on_point_ = num_of_chips_on_point; };
	int get_num_of_chips_on_point() { return num_of_chips_on_point_; };

	void add_chip() { num_of_chips_on_point_++; };
	void remove_chip() { num_of_chips_on_point_--; };

private:
	int num_of_chips_on_point_;
};

} // namespace Backgammon


#include "pch.h"
#include "../BackgammonEngine/Points.cpp"

namespace Backgammon
{

TEST(BackgammonTest, test_add_chip)
{
	Point point;
	EXPECT_EQ(point.get_num_of_chips_on_point(), 0);
	point.add_chip(Chip::Color::WHITE);
	EXPECT_EQ(point.get_num_of_chips_on_point(), 1);
}

TEST(BackgammonTest, test_remove_chip)
{
	Point point;
	point.add_chip(Chip::Color::WHITE);
	EXPECT_EQ(point.get_num_of_chips_on_point(), 1);
	point.remove_last_chip();
	EXPECT_EQ(point.get_num_of_chips_on_point(), 0);
}
TEST(BackgammonTest, test_check_if_point_empty) 
{
	Point point;
	EXPECT_TRUE(point.check_if_point_empty());
	point.add_chip(Chip::Color::WHITE);
	EXPECT_FALSE(point.check_if_point_empty());
}

TEST(BackgammonTest, test_get_first_chip_color)
{
	Point point;
	EXPECT_THROW(point.get_first_chip_color(), std::exception);
	point.add_chip(Chip::Color::BLACK);
	EXPECT_EQ(point.get_first_chip_color(), Chip::Color::BLACK);
}

TEST(BackgammonTest, test_set_num_of_chips_on_point)
{
	Point point;
	EXPECT_EQ(point.get_num_of_chips_on_point(), 0);
	point.set_num_of_chips_on_point(5, Chip::Color::WHITE);
	EXPECT_EQ(point.get_num_of_chips_on_point(), 5);
	EXPECT_EQ(point.get_first_chip_color(), Chip::Color::WHITE);
}

} // namespace Backgammon
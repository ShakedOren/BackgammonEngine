#include "pch.h"
#include "../BackgammonEngine/Chip.h"

namespace Backgammon
{
TEST(BackgammonTest, test_get_chip_color) {
	Chip chip(Chip::Color::WHITE);
	EXPECT_EQ(chip.get_chip_color(), Chip::Color::WHITE);
}

} // namespace Backgammon
#include "Board.h"

namespace Backgammon
{
void Board::print_board()
{
	auto full_board = get_full_board();
	
	unsigned int bla = Player::NUM_OF_POINTS / 2;
	for (size_t i = 0; i < bla; i++)
	{
		std::cout << full_board[i].get_num_of_chips_on_point() << " ";
	}
	std::cout << std::endl;
	for (size_t i = Player::NUM_OF_POINTS - 1; i >= bla; i--)
	{
		std::cout << full_board[i].get_num_of_chips_on_point() << " ";
	}
	std::cout << std::endl;
}

std::vector<Point> Board::get_full_board()
{
	std::vector<Point> player1_points = player1_.get_points();
	std::vector<Point> player2_points = player2_.get_points();
	std::vector<Point> full_board(Player::NUM_OF_POINTS);
	std::reverse(player2_points.begin(), player2_points.end());

	for (size_t i = 0; i < Player::NUM_OF_POINTS; i++)
	{
		if (player1_points[i].get_num_of_chips_on_point() != 0)
		{
			full_board[i] = player1_points[i];
		}
		if (player2_points[i].get_num_of_chips_on_point() != 0)
		{
			full_board[i] = player2_points[i];
		}
	}

	return full_board;
}

} // namespace Backgammon

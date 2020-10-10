#include "Board.h"

namespace Backgammon
{

Board::Board()
{
	players_.emplace_back(Chip::Color::WHITE);
	players_.emplace_back(Chip::Color::WHITE);
}

Player& Board::get_player(int player_id)
{
	if (players_.size() <= player_id)
	{
		// Exceptions
	}

	return players_[player_id];
}

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
	std::vector<Point> player1_points = get_player(0).get_points();
	std::vector<Point> player2_points = get_player(1).get_points();
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

void Board::move_chip(int player_id, int src_point, int dst_point)
{
	get_player(player_id).move_chip(src_point, dst_point);
}

} // namespace Backgammon

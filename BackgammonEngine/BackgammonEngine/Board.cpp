#include "Board.h"

namespace Backgammon
{

Board::Board()
{
	players_.emplace_back(Chip::Color::WHITE);
	players_.emplace_back(Chip::Color::BLACK);
}

Player& Board::get_player(PlayerId player_id)
{
	return players_[static_cast<unsigned int>(player_id)];
}

void Board::print_board()
{
	auto full_board = get_full_board();
	
	unsigned int bla = Player::NUM_OF_POINTS / 2;
	for (size_t i = 0; i < bla; i++)
	{
		int num_of_chips = full_board[i].get_num_of_chips_on_point();
		if (num_of_chips != 0)
		{
			if (full_board[i].get_first_chip_color() == Chip::Color::WHITE)
				std::cout << "W:";
			else
				std::cout << "B:";
		}
		std::cout << full_board[i].get_num_of_chips_on_point() << " ";
	}
	std::cout << std::endl;
	for (size_t i = Player::NUM_OF_POINTS - 1; i >= bla; i--)
	{
		int num_of_chips = full_board[i].get_num_of_chips_on_point();
		if (num_of_chips != 0)
		{
			if (full_board[i].get_first_chip_color() == Chip::Color::WHITE)
				std::cout << "W:";
			else
				std::cout << "B:";
		}
		std::cout << full_board[i].get_num_of_chips_on_point() << " ";
	}
	std::cout << std::endl;
}

std::vector<Point> Board::get_full_board()
{
	std::vector<Point> player1_points = get_player(PlayerId::PLAYER1).get_points();
	std::vector<Point> player2_points = get_player(PlayerId::PLAYER2).get_points();
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

void Board::move_chip(PlayerId player_id, int src_point, int dst_point)
{
	if (!check_if_move_valid(player_id, src_point, dst_point))
	{
		return;
		//TODO: Throw exception
	}
	get_player(player_id).move_chip(src_point, dst_point);
}

bool Board::check_if_move_valid(PlayerId player_id, int src_point, int dst_point)
{
	auto player = get_player(player_id);

	if (check_if_point_is_empty(player_id, src_point))
	{
		return false;
	}
	if (!check_if_point_is_empty(get_other_player_id(player_id),
		pos_from_end_to_pos_from_start(dst_point)))
	{
		return false;
	}

	return true;
}

bool Board::check_if_point_is_empty(PlayerId player_id, int point_id)
{
	return get_player(player_id).get_points()[point_id].check_if_point_empty();
}

Board::PlayerId Board::get_other_player_id(PlayerId player_id)
{
	return player_id == PlayerId::PLAYER1 ? PlayerId::PLAYER2 : PlayerId::PLAYER1;
}

int Board::pos_from_end_to_pos_from_start(int point_id_from_end)
{
	return Player::NUM_OF_POINTS - point_id_from_end - 1;
}
} // namespace Backgammon

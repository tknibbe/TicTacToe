/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:39:22 by tknibbe           #+#    #+#             */
/*   Updated: 2023/07/26 16:39:52 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tictactoe.h"

int	check_horizontal(int **board, int col)
{
	int	player;
	int	row;

	if (board[col][0] == 0)
		return (0);
	row = 0;
	player = board[col][0];
	while (row < 3 && player == board[col][row])
		row++;
	if (row == 3)
		return (1);
	return (0);
}

int	check_vertical(int **board, int row)
{
	int	player;
	int col;

	if (board[0][row] == 0)
		return (0);
	col = 0;
	player = board[0][row];
	while (col < 3 && player == board[col][row])
		col++;
	if (col == 3)
		return (1);
	return (0);
}

int	check_diagonal(int	**board, int col)
{
	int	player;
	int	row;
	int	dir = -1;

	if (board[col][0] == 0)
		return (0);
	if (col == 0)
		dir = 1;
	player = board[col][0];
	row = 0;
	while (row < 3)
	{
		if (board[col][row] != player)
			return (0);
		row++;
		col += dir;
	}
	return (1);
}

int	win_check(t_tic *game)
{
	int	pos = 0;
	if (game->moves_made < 5)
		return (0);
	while (pos < 3)
	{
		if (check_horizontal(game->board, pos))
			return (1);
		if (check_vertical(game->board, pos))
			return (1);
		pos++;
	}
	if (check_diagonal(game->board, 0) || check_diagonal(game->board, 2))
		return (1);
	return (0);
}
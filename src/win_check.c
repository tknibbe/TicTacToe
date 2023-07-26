/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:39:22 by tknibbe           #+#    #+#             */
/*   Updated: 2023/07/26 14:08:31 by tknibbe          ###   ########.fr       */
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

int	check_diagonal(int	**board, int col)
{
	int	player;
	int	row;
	int	dir;

	if (board[col][0] == 0)
		return (0);
	if (col == 0)
		dir = 1;
	else
		dir = -1;
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

int	check_cols(int	**board)
{
	int	col = 0;
	while (col < 3)
	{
		if (check_horizontal(board, col))
			return (1);
		else if (col != 1)
			if (check_diagonal(board, col))
				return (1);
		col++;
	}
	return (0);
}

int	check_rows(int **board)
{
	int	row = 0;
	int	col = 0;
	int	player;

	while(row < 3)
	{
		player = board[0][row];
		if (board[0][row] == 0)
		{
			row++;
			continue ;
		}
		while(col < 3 && player == board[col][row])
			col++;
		if (col == 3)
			return (1);
		col = 0;
		row++;
	}
	return (0);
}

int	win_check(int **board)
{
	return (check_cols(board) || check_rows(board));
}
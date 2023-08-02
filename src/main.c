/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tymonknibbe <tymonknibbe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:15:07 by tknibbe           #+#    #+#             */
/*   Updated: 2023/08/02 11:48:22 by tymonknibbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tictactoe.h"

void	put_in_array(t_tic *game, int row, int col)
{
	if (game->board[col][row] != 0)
	{
		printf("that's illegal :O\nyou get one retry\n");
		col = get_input("column") - 1;
		row = get_input("row") - 1;
		if (game->board[col][row] != 0)
		{
			printf("you had to ruin it huh :(\n");
			exit(0);
		}
	}
	if (game->moves_made % 2)
		game->board[col][row] = 1;
	else
		game->board[col][row] = 2;
	game->moves_made++;
	print_board(game->board);
}

void	play(t_tic *game)
{
	int	col;
	int	row;

	while (win_check(game) == 0 && game->moves_made < 9)
	{
		printf("\n\nPlayer #%d, make your move:\n", game->moves_made % 2 + 1);
		col = get_input("column (vertical)");
		row = get_input("row (horizontal)");
		put_in_array(game, row - 1, col - 1);
	}
	if (game->moves_made == 9)
		printf("NO WINNER\n");
	else
		printf("WINNER FOUND! congrats\nthe game was concluded in %d moves\n", game->moves_made);
}

int	main(void)
{
	t_tic	*game;

	init_game(&game);
	print_board(game->board);
	play(game);
}

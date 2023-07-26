/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:16:55 by tknibbe           #+#    #+#             */
/*   Updated: 2023/07/26 13:50:39 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TICTACTOE
# define TICTACTOE

#include <stdio.h>
#include <stdlib.h>

typedef struct s_tic
{
	int	**board;
	int	moves_made;
}			t_tic;


void	print_board(int	**board);
void	init_game(t_tic **game);
int		get_input(char *str);
int		win_check(int **board);

#endif
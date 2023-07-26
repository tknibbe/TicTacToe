/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:21:17 by tknibbe           #+#    #+#             */
/*   Updated: 2023/07/26 15:45:18 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tictactoe.h"

void init_game(t_tic **game)
{
	int	i;
	int	j;

	(*game) = malloc(sizeof(t_tic));
	(*game)->board = malloc(sizeof(int *) * 3);
	(*game)->moves_made = 0;
	while (i < 3)
	{
		(*game)->board[i] = malloc(sizeof(int) * 3);
		while (j < 3)
		{
			(*game)->board[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int	get_input(char *str)
{
	int	ret;
	
	while (1)
	{
		printf("\nenter %s :", str);
		scanf("%d", &ret);
		if (ret > 3 || ret < 1)
			printf("row must be between 1 and 3\n");
		else
			break ;
	}
	return (ret);
}

void	print_board(int	**board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("   1  2  3\n");
	while (i < 3)
	{
		printf("%d ", i + 1);
		while (j < 3)
		{
			if (board[i][j] == 0)
				printf("[ ]");
			else if (board[i][j] == 1)
				printf("[O]");
			else if (board[i][j] == 2)
				printf("[X]");
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}
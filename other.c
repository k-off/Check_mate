/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   other.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 10:42:17 by exam          #+#    #+#                 */
/*   Updated: 2019/02/12 13:25:17 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int				queen(int side, char **argv, int y, int x)
{
	return (rook_oriz(side, argv, y, x) || bishop_md_1(side, argv, y, x));
}

int				pawn(int side, char **argv, int y, int x)
{
	if (y - 1 >= 0 && x - 1 >= 0 && argv[y - 1][x - 1] == 'K')
		return (1);
	if (y - 1 >= 0 && x + 1 < side && argv[y - 1][x + 1] == 'K')
		return (1);
	if (y + 1 <= side && x - 1 >= 0 && argv[y + 1][x - 1] == 'K')
		return (1);
	if (y + 1 <= side && x + 1 < side && argv[y + 1][x + 1] == 'K')
		return (1);
	return (0);
}

static int		rook_vert(int side, char **argv, int y, int x)
{
	int		tmp_y;

	tmp_y = y;
	while (++tmp_y <= side)
	{
		if (argv[tmp_y][x] == 'K')
			return (1);
		if (argv[tmp_y][x] == 'B' || argv[tmp_y][x] == 'Q'
			|| argv[tmp_y][x] == 'P' || argv[tmp_y][x] == 'R')
			break ;
	}
	tmp_y = y;
	while (--tmp_y >= 1)
	{
		if (argv[tmp_y][x] == 'K')
			return (1);
		if (argv[tmp_y][x] == 'B' || argv[tmp_y][x] == 'Q'
			|| argv[tmp_y][x] == 'P' || argv[tmp_y][x] == 'R')
			break ;
	}
	return (0);
}

int				rook_oriz(int side, char **argv, int y, int x)
{
	int		tmp_x;

	tmp_x = x;
	while (++tmp_x < side)
	{
		if (argv[y][tmp_x] == 'K')
			return (1);
		if (argv[y][tmp_x] == 'B' || argv[y][tmp_x] == 'Q'
			|| argv[y][tmp_x] == 'P' || argv[y][tmp_x] == 'R')
			break ;
	}
	tmp_x = x;
	while (--tmp_x >= 0)
	{
		if (argv[y][tmp_x] == 'K')
			return (1);
		if (argv[y][tmp_x] == 'B' || argv[y][tmp_x] == 'Q'
			|| argv[y][tmp_x] == 'P' || argv[y][tmp_x] == 'R')
			break ;
	}
	return (rook_vert(side, argv, y, x));
}

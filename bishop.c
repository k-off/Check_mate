/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_mate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 10:42:17 by exam          #+#    #+#                 */
/*   Updated: 2019/02/12 13:23:33 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static int		bishop_ad_2(int side, char **argv, int y, int x)
{
	int		tmp_y;
	int		tmp_x;

	tmp_y = y;
	tmp_x = x;
	while (--y >= 1 && ++x < side)
	{
		if (argv[y][x] == 'K')
			return (1);
		if (argv[y][x] == 'B' || argv[y][x] == 'Q'
			|| argv[y][x] == 'P' || argv[y][x] == 'R')
			break ;
	}
	return (0);
}

static int		bishop_md_2(int side, char **argv, int y, int x)
{
	int		tmp_y;
	int		tmp_x;

	tmp_y = y;
	tmp_x = x;
	while (--y >= 1 && --x >= 0)
	{
		if (argv[y][x] == 'K')
			return (1);
		if (argv[y][x] == 'B' || argv[y][x] == 'Q'
			|| argv[y][x] == 'P' || argv[y][x] == 'R')
			break ;
	}
	return (bishop_ad_2(side, argv, tmp_y, tmp_x));
}

static int		bishop_ad_1(int side, char **argv, int y, int x)
{
	int		tmp_y;
	int		tmp_x;

	tmp_y = y;
	tmp_x = x;
	while (++y <= side && --x >= 0)
	{
		if (argv[y][x] == 'K')
			return (1);
		if (argv[y][x] == 'B' || argv[y][x] == 'Q'
			|| argv[y][x] == 'P' || argv[y][x] == 'R')
			break ;
	}
	return (bishop_md_2(side, argv, tmp_y, tmp_x));
}

int				bishop_md_1(int side, char **argv, int y, int x)
{
	int		tmp_y;
	int		tmp_x;

	tmp_y = y;
	tmp_x = x;
	while (++y <= side && ++x < side)
	{
		if (argv[y][x] == 'K')
			return (1);
		if (argv[y][x] == 'B' || argv[y][x] == 'Q'
			|| argv[y][x] == 'P' || argv[y][x] == 'R')
			break ;
	}
	return (bishop_ad_1(side, argv, tmp_y, tmp_x));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_mate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 10:42:17 by exam          #+#    #+#                 */
/*   Updated: 2019/02/12 13:25:37 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static void		ft_putstr(char *s)
{
	while (s[0])
	{
		write(1, s, 1);
		s++;
	}
}

static int		check_desk(int side, char **argv)
{
	int		y;
	int		x;

	y = 1;
	while (y <= side)
	{
		x = 0;
		while (x < side)
		{
			if ((argv[y][x] == 'P' && pawn(side, argv, y, x))
			|| (argv[y][x] == 'R' && rook_oriz(side, argv, y, x))
			|| (argv[y][x] == 'B' && bishop_md_1(side, argv, y, x))
			|| (argv[y][x] == 'Q' && queen(side, argv, y, x)))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int		side;

	side = argc - 1;
	if (argc > 1)
	{
		if (check_desk(side, argv) == 1)
			ft_putstr("Success");
		else
			ft_putstr("Fail");
	}
	ft_putstr("\n");
	return (0);
}

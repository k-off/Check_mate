/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_mate.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 10:42:17 by exam          #+#    #+#                 */
/*   Updated: 2019/02/12 10:42:17 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHECK_MATE_H
# define __CHECK_MATE_H

# include <unistd.h>

int		pawn(int side, char **argv, int i, int j);
int		rook_oriz(int side, char **argv, int i, int j);
int		bishop_md_1(int side, char **argv, int i, int j);
int		queen(int side, char **argv, int i, int j);
int		main(int argc, char **argv);

#endif

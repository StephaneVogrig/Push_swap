/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:46 by stephane          #+#    #+#             */
/*   Updated: 2024/02/05 00:24:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	move_build_ra_rb(int ra, int rb)
{
	t_moves	move;

	moves_init(&move);
	if (ra > rb)
	{
		move.ra = ra - rb;
		move.rr = rb;
		move.nbr = ra;
	}
	else
	{
		move.rb = rb - ra;
		move.rr = ra;
		move.nbr = rb;
	}
	move.pa = 1;
	move.nbr++;
	return (move);
}

t_moves	move_build_rra_rrb(int rra, int rrb)
{
	t_moves	move;

	moves_init(&move);
	if (rra > rrb)
	{
		move.rra = rra - rrb;
		move.rrr = rrb;
		move.nbr = rra;
	}
	else
	{
		move.rrb = rrb - rra;
		move.rrr = rra;
		move.nbr = rrb;
	}
	move.pa = 1;
	move.nbr++;
	return (move);
}

t_moves	move_build_ra_rrb(int ra, int rrb)
{
	t_moves	move;

	moves_init(&move);
	move.ra = ra;
	move.rrb = rrb;
	move.pa = 1;
	move.nbr = ra + rrb + 1;
	return (move);
}

t_moves	move_build_rb_rra(int rb, int rra)
{
	t_moves	move;

	moves_init(&move);
	move.rra = rra;
	move.rb = rb;
	move.pa = 1;
	move.nbr = rb + rra + 1;
	return (move);
}

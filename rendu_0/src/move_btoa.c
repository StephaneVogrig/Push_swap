/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:14:15 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/05 00:43:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	move_btoa_compute(t_psstack *stack_a, t_psstack *stack_b, \
		int pos_in_a, int pos_in_b)
{
	int		max_r;
	int		max_rr;
	int		rra;
	int		rrb;
	int		min_move;

	if (pos_in_a == stack_a->nbr)
		pos_in_a = 0;
	rra = 0;
	if (pos_in_a)
		rra = stack_a->nbr - pos_in_a;
	rrb = 0;
	if (pos_in_b)
		rrb = stack_b->nbr - pos_in_b;
	max_r = si32_max(pos_in_a, pos_in_b);
	max_rr = si32_max(rra, rrb);
	min_move = si32_min(max_r, si32_min(max_rr, pos_in_a + rrb));
	if (min_move > pos_in_b + rra)
		return (move_build_rb_rra(pos_in_b, rra));
	if (max_r == min_move)
		return (move_build_ra_rb(pos_in_a, pos_in_b));
	if (max_rr == min_move)
		return (move_build_rra_rrb(rra, rrb));
	return (move_build_ra_rrb(pos_in_a, rrb));
}

static t_moves	best_move_btoa(t_psstack *stack_a, t_psstack *stack_b)
{
	t_pslist	*current;
	int			i;
	t_moves		move;
	t_moves		best_move;
	int			pos_in_a;

	moves_init(&best_move);
	if (stack_b->nbr == 0)
		return (best_move);
	pos_in_a = position_insert_nbr(stack_a, stack_b->first->nbr);
	best_move = move_btoa_compute(stack_a, stack_b, pos_in_a, 0);
	current = stack_b->first->next;
	i = 1;
	while (current)
	{
		pos_in_a = position_insert_nbr(stack_a, current->nbr);
		move = move_btoa_compute(stack_a, stack_b, pos_in_a, i);
		if (move.nbr < best_move.nbr)
			best_move = move;
		i++;
		current = current->next;
	}
	return (best_move);
}

void	move_btoa(t_psstack *stack_a, t_psstack *stack_b)
{
	t_moves	move;

	while (stack_b->nbr)
	{
		move = best_move_btoa(stack_a, stack_b);
		move_do(&move, stack_a, stack_b);
	}
}

void	move_min_to_top(t_psstack *stack)
{
	int				i;
	t_pslist_pos	min;

	min = position_of_min(stack);
	i = min.i;
	if (i < stack->nbr / 2)
		while (i--)
			ra(stack);
	else
	{
		i = stack->nbr - i;
		while (i--)
			rra(stack);
	}
}

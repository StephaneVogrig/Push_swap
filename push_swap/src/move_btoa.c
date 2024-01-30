/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:14:15 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/30 17:57:25 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	compute_i(t_psstack *stack, int ref_nbr)
{
	int			i;
	int			current_nbr;
	t_pslist	*current;

	if (stack->first->nbr < stack->last->nbr || stack->nbr == 1)
		return (0);
	i = 0;
	current = stack->first;
	current_nbr = ref_nbr;
	while (current && current->nbr > current_nbr)
	{
		i++;
		current_nbr = current->nbr;
		current = current->next;
	}
	while (current && ref_nbr > current->nbr)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	compute_move_in_a(t_moves *move, int nbr, t_psstack *stack)
{
	int			i;

	i = position_insert_nbr(stack, nbr);
	if (i <= (stack->nbr / 2))
		move->ra = i;
	else
		move->rra = stack->nbr - i;
}

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
	min_move = max_r;
	if (min_move > max_rr)
		min_move = max_rr;
	if (min_move > pos_in_a + rrb)
		min_move = pos_in_a + rrb;
	if (min_move > pos_in_b + rra)
		return (move_build_rb_rra(pos_in_b, rra));
	if (max_r == min_move)
		return (move_build_ra_rb(pos_in_a, pos_in_b));
	if (max_rr == min_move)
		return (move_build_rra_rrb(rra, rrb));
	return (move_build_ra_rrb(pos_in_a, rrb));
}

t_moves	compute_move(t_psstack *stack_a, int stack_b_nbr, int i, int nbr)
{
	t_moves		move;
	int			median;

	moves_init(&move);
	median = stack_b_nbr / 2;
	if (i <= median)
		move.rb = i;
	else
		move.rrb = stack_b_nbr - i;
	move.pa = 1;
	compute_move_in_a(&move, nbr, stack_a);
	moves_reduce_r(&move);
	moves_reduce_rr(&move);
	moves_count(&move);
	return (move);
}

static t_moves	best_move_btoa(t_psstack *stack_a, t_psstack *stack_b)
{
	t_pslist	*current;
	int			i;
	t_moves		move;
	t_moves		best_move;

	moves_init(&best_move);
	if (stack_b->nbr == 0)
		return (best_move);
	// best_move = compute_move(stack_a, stack_b->nbr, 0, stack_b->first->nbr);
	best_move = move_btoa_compute(stack_a, stack_b, position_insert_nbr(stack_a, stack_b->first->nbr), 0);
	current = stack_b->first->next;
	i = 1;
	while (current)
	{
		// move = compute_move(stack_a, stack_b->nbr, i, current->nbr);
		move = move_btoa_compute(stack_a, stack_b, position_insert_nbr(stack_a, current->nbr), i);
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
	int	i;
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

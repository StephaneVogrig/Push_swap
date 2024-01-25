/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:14:15 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/25 18:49:22 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	t_pslist	*current;

	if (stack->nbr == 0)
		return ;
	i = 0;
	current = stack->first;
	while (current && nbr > current->nbr)
	{
		i++;
		current = current->next;
	}
	if (i == 0)
		i = compute_i(stack, nbr);

	// i = position_insert_nbr(stack, nbr);

	if (i <= (stack->nbr / 2))
		move->ra = i;
	else
		move->rra = stack->nbr - i;
}

t_moves	compute_move(t_psstack *stack_a, int stack_b_nbr, int i, int nbr)
{
	t_moves		move;
	int			median;

	moves_init(&move);
	if (stack_a->nbr == 0)
		return (move);
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
	best_move = compute_move(stack_a, stack_b->nbr, 0, stack_b->first->nbr);
	current = stack_b->first->next;
	i = 1;
	while (current)
	{
		move = compute_move(stack_a, stack_b->nbr, i, current->nbr);
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

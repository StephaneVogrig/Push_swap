/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 03:17:39 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/26 03:18:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_psstack *stack)
{
	int			previous_nbr;
	t_pslist	*current;

	if (stack->nbr < 2)
		return (TRUE);
	previous_nbr = stack->first->nbr;
	current = stack->first->next;
	while (current)
	{
		if (current->nbr < previous_nbr)
			return (FALSE);
		previous_nbr = current->nbr;
		current = current->next;
	}
	return (TRUE);
}

void	ps_sort_2(t_psstack *stack)
{
	if (stack->first->nbr > stack->first->next->nbr)
		sa(stack);
}

void	ps_sort_3(t_psstack *stack)
{
	t_pslist	*list;

	list = stack->first;
	if (list->index > list->next->index && list->index > stack->last->index)
		ra(stack);
	else if (list->next->index > stack->last->index)
		rra(stack);
	if (stack->first->index > stack->first->next->index)
		sa(stack);
}

void	ps_sort_5(t_psstack *stack_a)
{
	t_psstack	stack_b;

	ps_stack_init(&stack_b);
	if (stack_a->last->index == 0)
		rra(stack_a);
	while (stack_a->nbr > 3)
	{
		while (stack_a->first->nbr > stack_a->last->nbr)
			ra(stack_a);
		pb(stack_a, &stack_b);
	}
	ps_sort_3(stack_a);
	move_btoa(stack_a, &stack_b);
	move_min_to_top(stack_a);
}

void	ps_sort(t_psstack *stack_a)
{
	t_psstack	stack_b;

	ps_stack_init(&stack_b);
	int			limit;
	int			range;
	int			i;
	int			n;

	range = stack_a->nbr / 2;
	limit = range;
	while (range > 32)
	{
		i = 0;
		n = stack_a->nbr;
		range /= 2;
		while (i < n)
		{
			// if (!stack_a->first->in_lis && !stack_a->first->next->in_lis)
			// 	if (stack_a->first->index > stack_a->first->next->index)
			// 		sa(stack_a);
			
			if (stack_a->first->in_lis || stack_a->first->index > limit)
			{
				if (stack_b.first && stack_b.first->index < (limit - range))
					rr(stack_a, &stack_b);
				else
					ra(stack_a);
			}
			else
			{
				if (stack_b.first && stack_b.first->index < (limit - range))
					rb(&stack_b);
				pb(stack_a, &stack_b);
			}
			i++;
		}
		limit += range;
	}
	while (!is_sorted(stack_a))
	{
		if (stack_a->first->in_lis)
			ra(stack_a);
		else
			pb(stack_a, &stack_b);
		if (stack_b.first && stack_b.first->index < limit)
			rb(&stack_b);
	}
	move_btoa(stack_a, &stack_b);
	move_min_to_top(stack_a);;
}

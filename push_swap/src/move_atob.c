/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:21:10 by stephane          #+#    #+#             */
/*   Updated: 2024/01/29 23:44:45 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	move_atob_pb(t_psstack *stack_a, t_psstack *stack_b, int limit)
{
	if (stack_b->first && stack_b->first->index < limit)
		rb(stack_b);
	pb(stack_a, stack_b);
}


void	move_atob_ra(t_psstack *stack_a, t_psstack *stack_b, int limit)
{
	if (stack_b->first && stack_b->first->index < limit)
		rr(stack_a, stack_b);
	else
		ra(stack_a);	
}

void	move_atob_limit(t_psstack *stack_a, t_psstack *stack_b, int limit, int range)
{
	int			i;
	int			n;
	
	n = stack_a->nbr;
	i = 0;
	while (i < n)
	{
		if (stack_a->first->in_lis || stack_a->first->index > limit)
			move_atob_ra(stack_a, stack_b, limit - range);
		else
			move_atob_pb(stack_a, stack_b, limit - range);
		i++;
	}
}

void	move_atob(t_psstack *stack_a, t_psstack *stack_b)
{
	int			limit;
	int			range;

	range = stack_a->nbr / 2;
	limit = range;
	while (range > 32)
	{
		range /= 2;
		move_atob_limit(stack_a, stack_b, limit, range);
		limit += range;
	}
	while (!is_sorted(stack_a))
	{
		if (stack_a->first->in_lis)
			move_atob_ra(stack_a, stack_b, limit);
		else
			move_atob_pb(stack_a, stack_b, limit);
	}
}

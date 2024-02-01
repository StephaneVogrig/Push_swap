/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:00:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/01 18:36:10 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	lo_compute(int hi, int *x, int *m, int i)
{
	int lo;
	int	mid;

   	lo = 1;
	while (lo < hi)
		{
        	mid = lo + ((hi-lo)/2);
        	if (x[m[mid]] >= x[i])
            	hi = mid;
        	else
            	lo = mid + 1;
		}
	return (lo);
}

void	lis_to_stack(t_psstack *stack, int *m, int len)
{
	int			i;
	t_pslist	*current;

	i = 0;
	current = stack->first;
	while (len--)
	{
		while (i < *m)
		{
			i++;
			current = current->next;
		}
		current->in_lis = 1;
		m++;
	}
}

void	lis_to_index(int i, int *m, int *p)
{
	int	k;
	k = m[i];
	while (i--)
	{
		m[i] = k;
		k = p[k];
	}
}

void	lis_compute(t_psstack *stack, int *p, int *m, int *x)
{
	int	lis_len;
	int	new_len;
	int	i;
	
	ps_stack_to_array(stack, x);
	m[0] = -1;
	lis_len = 0;
	i = 0;
	while (i < stack->nbr)
	{
		new_len = lo_compute(lis_len + 1, x, m, i);
		p[i] = m[new_len-1];
		m[new_len] = i;
		if (new_len > lis_len)
			lis_len = new_len;
		i++;
	}
	lis_to_index(lis_len, m, p);
	lis_to_stack(stack, m, lis_len);
}

int	lis(t_psstack *stack)
{
	int	*p;
	int	*m;
	int *x;

	p = malloc(sizeof(int) * stack->nbr);
	x = malloc(sizeof(int) * stack->nbr);
	m = malloc(sizeof(int) * (stack->nbr + 1));
	if (p && m && x)
		lis_compute(stack, p, m, x);
	if (p)
		free(p);
	if (m)
		free(m);
	if (x)
		free(x);
	if (p && m && x)
		return (SUCCESS);
	return (ERROR);
}

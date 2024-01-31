/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:00:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/31 03:30:06 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

typedef struct s_tabsi32{
	int	*tab;
	int	size;
}	t_tabsi32;

t_tabsi32	tabsi32_init(int *tab, int size)
{
	t_tabsi32	new;

	new.tab = tab;
	new.size = size;
	return (new);
}

void	tabsi32_print(t_tabsi32 d, char *before, char *sep, char *after)
{
	ft_putstr_fd(before, 1);
	while (d.size--)
	{
		ft_putnbr_fd(*(d.tab++), 1);
		if (d.size)
			ft_putstr_fd(sep, 1);
	}
	ft_putstr_fd(after, 1);
}

void	stack_to_array(t_psstack *stack, int *x)
{
	t_pslist	*current;

	current = stack->first;
	while (current)
	{
		*x++ = current->nbr;
		current = current->next;
	}
}

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
	// ft_printf("start list to stack len = %i\n", len);
	while (len--)
	{
		while (i < *m)
		{
			i++;
			current = current->next;
		}
		current->in_lis = 1;
		m++;
		// ft_printf("%i ", current->nbr);
	}
		// ft_printf("\n");
		// ft_printf("\n", current->nbr);
}

void	lis_to_index(int i, int *m, int *p)
{
	int	k;
	k = m[i];
	while (i--)
	{
		// ft_printf("L = %i | k : %i\n", i, k);
		m[i] = k;
		k = p[k];
	}
}

void	lis_compute(t_psstack *stack, int *p, int *m, int *x)
{
	int	lis_len;
	int	new_len;
	int	i;
	
	stack_to_array(stack, x);

	// tabsi32_print(tabsi32_init(p, stack->nbr), "p = ", " ", " | ");
	// tabsi32_print(tabsi32_init(m, stack->nbr + 1), "m = ", " ", " | ");
	// tabsi32_print(tabsi32_init(x, stack->nbr), "x = ", " ", "\n");
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
	// ft_printf("%i : ", i);
	// tabsi32_print(tabsi32_init(p, stack->nbr), "p = ", " ", " | ");
	// tabsi32_print(tabsi32_init(m, stack->nbr + 1), "m = ", " ", " | ");
	// tabsi32_print(tabsi32_init(x, stack->nbr), "x = ", " ", " | ");
	// ft_printf("L : %i\n", lis_len);
		i++;
	}
	lis_to_index(lis_len, m, p);
	// ft_printf("end lis_compute len = %i\n", lis_len);
	// tabsi32_print(tabsi32_init(m, stack->nbr + 1), "m = ", " ", "\n");
	lis_to_stack(stack, m, lis_len);

	// t_pslist	*current = stack->first;
	// while (current)
	// {
	// 	if (current->in_lis)
	// 		ft_printf("%i ", current->nbr);
	// 	current = current->next;
	// }
	
	// 	ft_printf("\n");




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
	{
		lis_compute(stack, p, m, x);
		return (SUCCESS);
	}
	if (p)
		free(p);
	if (m)
		free(m);
	if (x)
		free(x);
	return (ERROR);
}

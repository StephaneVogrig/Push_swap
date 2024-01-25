/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:05:51 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/25 17:50:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_list.h"

t_pslist	*ps_list_new(int n)
{
	t_pslist	*new;

	new = malloc(sizeof(t_pslist));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	ps_list_free(t_pslist **list)
{
	t_pslist	*temp;
	t_pslist	*current;

	current = *list;
	*list = NULL;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

int	is_in_ps_list(int n, t_pslist *list)
{
	while (list)
	{
		if (list->nbr == n)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

t_pslist_pos	pslist_pos_init(void)
{
	t_pslist_pos	pslist_pos;

	pslist_pos.i = 0;
	pslist_pos.ptr = NULL;
	return (pslist_pos);
}

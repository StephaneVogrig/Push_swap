/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:18:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIST_H
# define PUSH_SWAP_LIST_H

# include "libft.h"

typedef struct s_pslist{
	int					nbr;
	int					index;
	struct s_pslist		*prev;
	struct s_pslist		*next;
}	t_pslist;

t_pslist	*ps_list_new(int n);
void		ps_list_free(t_pslist **list);
int			is_in_ps_list(int n, t_pslist *list);
char		*list_to_str(t_pslist *list, const char *sep);

#endif
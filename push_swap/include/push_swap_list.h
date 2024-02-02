/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/01 19:49:26 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_LIST_H
# define PUSH_SWAP_LIST_H

# include "libft.h"

typedef struct s_pslist{
	int					nbr;
	int					index;
	int					in_lis;
	struct s_pslist		*next;
}	t_pslist;

typedef struct s_pslist_position{
	int			i;
	t_pslist	*ptr;

}	t_pslist_pos;

t_pslist	*ps_list_new(int n);
void		ps_list_free(t_pslist **list);
int			is_in_ps_list(int n, t_pslist *list);
char		*list_to_str(t_pslist *list, const char *sep);


t_pslist_pos	pslist_pos_init(void);

#endif
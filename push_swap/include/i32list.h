/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 13:44:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I32_LIST_H
# define I32_LIST_H

# include "libft.h"

typedef struct	s_i32list {
	int					nbr;
	struct s_i32list	*prev;
	struct s_i32list	*next;
}	t_i32list;

t_i32list	*i32list_new(int n);
void		i32list_free(t_i32list **list);
void		i32list_print(t_i32list *list, const char *sep, const char *term);
int			is_in_i32list(int n, t_i32list *list);
char		*i32list_to_str(t_i32list *list, const char *sep);

#endif
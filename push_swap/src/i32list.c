/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:05:51 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 14:29:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "i32list.h"

t_i32list	*i32list_new(int n)
{
	t_i32list	*new;

	new = malloc(sizeof(t_i32list));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	i32list_free(t_i32list **list)
{
	t_i32list	*temp;
	t_i32list	*current;
	
	current = *list;
	*list = NULL;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

int	is_in_i32list(int n, t_i32list *list)
{
	while (list)
	{
		if (list->nbr == n)
			return (TRUE);
		list = list->next;	
	}
	return (FALSE);
}

void	i32list_print(t_i32list *list, const char *sep, const char *term)
{
	while (list)
	{
		if (list->next == NULL)
			ft_printf("%i%s", list->nbr, term);
		else
			ft_printf("%i%s", list->nbr, sep);
		list = list->next;
	}	
}

int	si32list_len(t_i32list *list, const char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (list)
	{
		len += nbr_digit_si32(list->nbr);
		list = list->next;
		i++;
	}
	if (i)
		len += (i - 1) * ft_strlen(sep);
	return (len);
}

char	*si32list_strcpy(char *str, const char *sep)
{
	while (*sep)
		*str++ = *sep++;
	return (str);
}

char	*i32list_to_str(t_i32list *list, const char *sep)
{
	char	*str;
	char	*offset;
	int		len;

	len = si32list_len(list, sep);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	offset = str;
	while (list)
	{
		offset = si32_to_decstr_offset(offset, list->nbr);
		if (list->next != NULL)
			offset = strcpy_offset(offset, sep);
		list = list->next;
	}
	return (str);
}

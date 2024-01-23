/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psut_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:10:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/22 23:09:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

int	psut_list_to_str_len(t_pslist *list, const char *sep)
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

char	*psut_list_to_str(t_pslist *list, const char *sep)
{
	char	*str;
	char	*offset;
	int		len;

	len = psut_list_to_str_len(list, sep);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
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

void	psut_list_print(t_pslist *list, const char *sep, const char *term)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32list_to_str_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:12:06 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 15:01:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_test(t_i32list *list, char *expected)
{
	char	*output;

	output = i32list_to_str(list, " ");
	if (!output)
	{
		ft_printf("Memory allocation failed!\n");
		return ;
	}
	if(ft_strcmp(output, expected) == 0)
	{
		unit_test(increase_success);
		if (VERBOSE)
		{
			ft_printf("input = %12s : \033[32m%12s\033[0m", expected, expected);
			ft_printf(" | \033[32m%12s[OK]\n\033[0m", output);
		}
	}
	else
	{
		ft_printf("input = %12s : \033[32m%12s\033[0m", expected, expected);
		ft_printf(" | \033[31m%12s[KO]\n\033[0m", output);
	}
	free(output);
	unit_test(increase_tests);
}

void	i32list_to_str_tests(void)
{
	t_i32list	*list;
	t_i32list	*new;

	unit_test(init);
	list = i32list_new(42);
	print_test(list, "42");
	new = i32list_new(0);
	list->next = new;
	print_test(list, "42 0");
	new = i32list_new(-42);
	list->next->next = new;
	print_test(list, "42 0 -42");
	i32list_free(&list);
	unit_test_print_result("i32list_new", 30);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psut_list_to_str_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:12:06 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:16:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test(t_pslist *list, char *expected)
{
	char	*output;
	int		success;

	output = psut_list_to_str(list, " ");
	if (!output)
	{
		ft_printf("Memory allocation failed!\n");
		return ;
	}
	success = ft_strcmp(output, expected) == 0;
	if (!success || VERBOSE)
		ft_printf("input = %12s : \033[32m%12s\033[0m", expected, expected);
	if (!success)
		ft_printf(" | \033[31m%12s[KO]\n\033[0m", output);
	if (VERBOSE)
		ft_printf(" | \033[32m%12s[OK]\n\033[0m", output);
	if (success)
		unit_test(increase_success);
	free(output);
	unit_test(increase_tests);
}

void	psut_list_to_str_tests(void)
{
	t_pslist	*list;
	t_pslist	*new;

	unit_test(init);
	list = ps_list_new(42);
	print_test(list, "42");
	new = ps_list_new(0);
	list->next = new;
	print_test(list, "42 0");
	new = ps_list_new(-42);
	list->next->next = new;
	print_test(list, "42 0 -42");
	ps_list_free(&list);
	unit_test_print_result("list_to_str", 30);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_new_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:14:47 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:16:17 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_unit_test.h"

static void	print_test(int n)
{
	t_pslist	*node;
	int			success;

	node = ps_list_new(n);
	if (!node)
		return ;
	success = node->nbr == n && node->next == NULL;
	if (!success || VERBOSE)
		ft_printf("input = %12i : \033[32m%12i, %p\033[0m", n, n, NULL);
	if (!success)
		ft_printf(" | \033[31m%12i, %p [KO]\n\033[0m", node->nbr, node->next);
	else if (VERBOSE)
		ft_printf(" | \033[32m%12i, %p [OK]\n\033[0m", node->nbr, node->next);
	if (success)
		unit_test(increase_success);
	free(node);
	unit_test(increase_tests);
}

void	ps_list_new_tests(void)
{
	unit_test(init);
	print_test(42);
	print_test(0);
	print_test(-42);
	unit_test_print_result("list_new", 30);
}

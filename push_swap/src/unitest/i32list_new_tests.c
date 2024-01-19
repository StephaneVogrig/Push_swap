/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32list_new_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:14:47 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/18 23:02:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_test(int	n)
{
	t_i32list	*node;

	node = i32list_new(n);
	if (!node)
	{
		ft_printf("Memory allocation error!\n");
		return ;
	}
	if(node->nbr == n && node->next == NULL)
	{
		unit_test(increase_success);
		if (VERBOSE)
		{
			ft_printf("input = %12i : \033[32m%12i, %p\033[0m", n, n, NULL);
			ft_printf(" | \033[32m%12i, %p [OK]\n\033[0m", node->nbr, node->next);
		}
	}
	else
	{
		ft_printf("input = %12i : \033[32m%12i, %p\033[0m", n, n, NULL);
		ft_printf(" | \033[31m%12i, %p [KO]\n\033[0m", node->nbr, node->next);
	}
	free(node);
	unit_test(increase_tests);
}

void	i32list_new_tests(void)
{
	unit_test(init);
	print_test(42);
	print_test(0);
	print_test(-42);
	unit_test_print_result("i32list_new", 30);
}

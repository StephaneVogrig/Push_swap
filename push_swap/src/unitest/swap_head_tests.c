/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_head_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:45:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 15:05:58 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_test(char *input, char *expected)
{
	char	*output;
	t_stack	stack;

	stack_init(&stack);
	arg_to_stack(input, &stack);
	swap_head(&stack);
	output = i32list_to_str(stack.first, " ");
	if(ft_strcmp(output, expected) == 0)
	{
		unit_test(increase_success);
		if (VERBOSE)
		{
			ft_printf("input = %12s :", input);
			ft_printf("\033[32m %12s \033[0m",expected);
			ft_printf("|\033[32m %12s [OK]\n\033[0m", output);
		}
	}
	else
	{
		ft_printf("input = %12s :", input);
		ft_printf("\033[32m %12s \033[0m",expected);
		ft_printf("|\033[31m %12s [KO]\n\033[0m", output);
	}
	stack_free(&stack);
	unit_test(increase_tests);
}

void	swap_head_tests(void)
{
	unit_test(init);
	print_test("","");
	print_test("1","1");
	print_test("5 1","1 5");
	print_test("0 1 2 3 4","1 0 2 3 4");
	unit_test_print_result("swap_head", 30);
}

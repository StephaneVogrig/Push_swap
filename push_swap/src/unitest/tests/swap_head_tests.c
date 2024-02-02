/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_head_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:45:25 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/01 19:22:17 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap_unit_test.h"

static void	print_test_2(char *input, char *expected, t_psstack stack)
{
	char	*output;
	int		success;

	output = psut_list_to_str(stack.first, " ");
	if (!output)
		return ;
	success = ft_strcmp(output, expected) == 0;
	if (!success || VERBOSE)
		ft_printf("input = %12s :\033[32m %12s \033[0m", input, expected);
	if (!success)
		ft_printf("|\033[32m %12s [OK]\n\033[0m", output);
	else if (VERBOSE)
		ft_printf("|\033[31m %12s [KO]\n\033[0m", output);
	free(output);
	if (success)
		unit_test(increase_success);
}

static void	print_test(char *input, char *expected)
{
	t_psstack	stack;

	ps_stack_init(&stack);
	if (!arg_to_stack(input, &stack))
		return ;
	swap(&stack);
	print_test_2(input, expected, stack);
	ps_stack_free(&stack);
	unit_test(increase_tests);
}

void	swap_head_tests(void)
{
	unit_test(init);
	print_test("", "");
	print_test("1", "1");
	print_test("5 1", "1 5");
	print_test("0 1 2 3 4", "1 0 2 3 4");
	unit_test_print_result("swap_head", 30);
}

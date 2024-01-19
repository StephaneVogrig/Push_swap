/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_stack_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:02:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 04:15:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* doit retourner error :
"" chaine vide
"                    " chaine uniquement constitue de space
"1+2" deux nombre sana espace entre eux
"1e2" chaine contenant autre chose que des digit des espaces ou des signes + -*/


#include "push_swap.h"

// must return NULL
static void	print_test_fail(char *input)
{
	t_stack	stack;
	char	*output;

	stack_init(&stack);
	output = number_to_stack(input, &stack);
	if (output)
	{
		ft_printf("input = %10s : \033[32m%10p\033[0m", input, NULL);
		ft_printf(" | \033[31m%10p [KO]\n\033[0m", output);
	}
	else
	{	
		unit_test(increase_success);
		if (VERBOSE)
		{
			ft_printf("input = %10s : \033[32m%10p\033[0m", input, NULL);
			ft_printf(" | \033[32m%10p [OK]\n\033[0m", output);
		}
	}
	unit_test(increase_tests);
}

static void	print_test(char *input, int expected)
{
	t_stack	stack;
	int		output;

	stack_init(&stack);
	number_to_stack(input, &stack);
	output = stack.first->nbr;
	if(output == expected)
	{
		unit_test(increase_success);
		if (VERBOSE)
		{
			ft_printf("input = %12s : \033[32m%12i\033[0m", input, expected);
			ft_printf(" | \033[32m%12i[OK]\n\033[0m", output);
		}
	}
	else
	{
		ft_printf("input = %12s : \033[32m%12i\033[0m", input, expected);
		ft_printf(" | \033[31m%12i[KO]\n\033[0m", output);
	}
	stack_free(&stack);
	unit_test(increase_tests);
}

void	number_to_stack_tests(void)
{
	unit_test(init);
	print_test_fail("+ 42");
	print_test_fail("+42+42");
	print_test("42", 42);
	print_test("0", 0);
	print_test("-42", -42);
	// print_test("+42", 42);
	// print_test("-42", -42);
	
	unit_test_print_result("number_to_stack", 30);

}

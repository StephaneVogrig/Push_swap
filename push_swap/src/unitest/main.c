/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:16:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/19 15:09:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_unit_test.h"

int	main(void)
{
	i32list_new_tests();
	number_to_stack_tests();
	si32_to_decstr_offset_tests();
	i32list_to_str_tests();
	arg_to_stack_tests();
	swap_head_tests();
	rotate_tests();
	return (0);
}

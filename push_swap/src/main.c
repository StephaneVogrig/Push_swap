/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:10:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/31 00:09:11 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_psstack	stack;
	int			ok;

	if (argc == 1)
		return (0);
	ps_stack_init(&stack);
	ok = args_to_stack(argc, argv, &stack);
	if (ok)
		ok = lis(&stack);
	if (ok && !is_sorted(&stack))
	{
		ps_index(stack.first);
		if (stack.nbr == 2)
			ps_sort_2(&stack);
		else if (stack.nbr == 3)
			ps_sort_3(&stack);
		else if (stack.nbr < 6)
			ps_sort_5(&stack);
		else
			ps_sort(&stack);
	}
	if (!ok)
		write(2, "Error\n", 6);
	ps_stack_free(&stack);
	return (0);
}

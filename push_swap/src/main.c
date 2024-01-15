/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:10:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/15 02:27:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (0);

	i = 1;
	while (i < argc)
	{
		if (parse(argv[i++]) == ERROR)
			return (write(2, "Error\n", 6)); 

		// printf("%s\n", argv[i]);


	}
	return (0);
}
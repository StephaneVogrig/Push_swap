/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabsi32_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:40:14 by stephane          #+#    #+#             */
/*   Updated: 2024/02/01 17:02:01 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	tabsi32_print(t_tabsi32 tab, char *before, char *sep, char *after)
{
	ft_putstr_fd(before, 1);
	while (tab.size--)
	{
		ft_putnbr_fd(*(tab.elem++), 1);
		if (tab.size)
			ft_putstr_fd(sep, 1);
	}
	ft_putstr_fd(after, 1);
}

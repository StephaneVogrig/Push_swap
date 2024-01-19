/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:45:03 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/18 19:36:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTE_H
# define CONSTANTE_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define ULLONG_MAX ((t_ui64)~0ULL)

# define LLONG_MAX ((t_si64)(ULLONG_MAX >> 1))
# define LLONG_MIN ((t_si64)(-LLONG_MAX - 1))

# define TRUE 1
# define FALSE 0

# define SUCCESS 1
# define ERROR 0

# ifndef NULL
#  define NULL ((void *)0)
# endif

#endif
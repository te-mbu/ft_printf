/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:38:19 by tembu             #+#    #+#             */
/*   Updated: 2020/02/23 16:04:40 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			small_atoi(const char *str, int *pos, size_t nb_value)
{
//	if (str[*pos] == '*')
//	{
//		nb_value = va_arg(args, int);
//		return (nb_value);
//	}
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		nb_value = nb_value * 10 + str[*pos] - 48;
		*pos += 1;
	}
	return (nb_value);
}

char		*min_2_plus(char **to_print)
{
	long long result;

	ft_putchar('-');
	result = ft_atoi(*to_print) * (-1);
	free(*to_print);
	*to_print = ft_itoa(result);
	return (*to_print);
}

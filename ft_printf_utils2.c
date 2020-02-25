/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:38:19 by tembu             #+#    #+#             */
/*   Updated: 2020/02/25 10:59:26 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			small_atoi(const char *str, int *pos, size_t nb_value)
{
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		nb_value = nb_value * 10 + str[*pos] - 48;
		*pos += 1;
	}
	return (nb_value);
}

int		len_ofnumber(int nb)
{
	if (nb < 0)
		return (1 + len_ofnumber(nb * (-1)));
	if (nb > 9)
		return (1 + len_ofnumber(nb / 10));
	return (1);
}
/*
static int			what_multiplicator(int len)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (i < len)
	{
		result = result * 10;
		i++;
	}
	return (result);
}
*/

int			small_atoi_final(const char *str, int *pos, size_t nb_value, t_flag my_struct)
{
	int multi;
	int len;

	multi = 0;
	len = 0;
	if (str[*pos] == '*')
	{
		nb_value = my_struct.star;
		return (nb_value);
	}
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		nb_value = nb_value * 10 + str[*pos] - 48;
		*pos += 1;
	}
	return (nb_value);
}
int			small_atoi_final2(const char *str, int *pos, size_t nb_value, t_flag my_struct)
{
	int multi;
	int len;

	multi = 0;
	len = 0;
	if (str[*pos] == '*')
	{
		nb_value = my_struct.star2;
		return (nb_value);
	}
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

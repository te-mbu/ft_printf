/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:38:19 by tembu             #+#    #+#             */
/*   Updated: 2020/03/04 11:54:57 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					len_ofnumber(int nb)
{
	if (nb < 0)
		return (1 + len_ofnumber(nb * (-1)));
	if (nb > 9)
		return (1 + len_ofnumber(nb / 10));
	return (1);
}

char				*min_2_plus(char **to_print)
{
	long long result;

	ft_putchar('-');
	result = ft_atoi(*to_print) * (-1);
	free(*to_print);
	*to_print = ft_itoa(result);
	return (*to_print);
}

static size_t		ft_atoi_2(const char *str, int *neg)
{
	int		i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

int					ft_atoi(const char *str)
{
	int		neg;
	size_t	result;

	neg = 1;
	result = ft_atoi_2(str, &neg);
	if (result > 9223372036854775807)
	{
		if (neg == 1)
			return (-1);
		if (neg == -1)
			return (0);
	}
	return ((int)result * neg);
}

int					ft_putstr_and_free(char *str, int i)
{
	int		l;

	l = 0;
	ft_putstr(str);
	if (i == 1)
		l = ft_len_to_print(&str);
	if (i == 0)
		free(str);
	return (l);
}

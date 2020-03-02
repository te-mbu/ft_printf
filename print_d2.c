/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:01:15 by tembu             #+#    #+#             */
/*   Updated: 2020/03/02 17:50:57 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_d_space(char *to_print, t_flag my_struct)
{
	int i;
	int len_to_print;

	i = 0;
	len_to_print = 0;
	if (my_struct.nb <= ft_strlen2(to_print))
	{
		my_struct.nb = 0;
		ft_putstr(to_print);
	}
	else
	{
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print);
		while (i++ < my_struct.nb)
			ft_putchar(' ');
		ft_putstr(to_print);
	}
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	return (my_struct.nb + len_to_print);
}

int					print_d_minus_space(char *to_print, t_flag my_struct)
{
	int		i;
	int		len_to_print;

	i = 0;
	len_to_print = 0;
	if (my_struct.nb <= ft_strlen2(to_print))
	{
		my_struct.nb = 0;
		ft_putstr(to_print);
	}
	else
	{
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print);
		ft_putstr(to_print);
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	}
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	return (my_struct.nb + ft_strlen2(to_print));
}

int					print_d_precision_plus2(t_flag my_struct, int plus_one,
						char *to_print, char *str_precision)
{
	int i;
	int len_to_print;

	i = 0;
	len_to_print = 0;
	if (my_struct.nb <= my_struct.nb2 + ft_strlen2(to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (my_struct.nb2
		+ ft_strlen2(to_print) + 1);
	else
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(to_print));
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	if (plus_one == 1)
		ft_putchar('-');
	ft_putstr(str_precision);
	free(str_precision);
	ft_putstr(to_print);
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	if (plus_one == 1)
		return (my_struct.nb + my_struct.nb2 + len_to_print + 1);
	return (my_struct.nb + my_struct.nb2 + len_to_print);
}

int					print_d_precision_plus(char *to_print, t_flag my_struct,
					int i, int plus_one)
{
	long long	result;
	char		*str_precision;

	if (to_print[0] == '-')
	{
		result = ft_atoi(to_print) * (-1);
		free(to_print);
		to_print = ft_itoa(result);
		plus_one = 1;
	}
	if (my_struct.nb2 <= ft_strlen2(to_print))
		my_struct.nb2 = 0;
	else if (my_struct.minus2 > 0)
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(to_print);
	if (!(str_precision = (char *)malloc(sizeof(char) * (my_struct.nb2 + 1))))
		return (0);
	while (++i < my_struct.nb2)
		str_precision[i] = '0';
	str_precision[i] = '\0';
	return (print_d_precision_plus2(my_struct, plus_one,
	to_print, str_precision));
}

int					print_d_precision_minus_sc1(t_flag my_struct,
						char *to_print, int plus_one)
{
	int i;
	int len_to_print;

	i = -1;
	len_to_print = 0;
	ft_putstr(to_print);
	if (my_struct.nb <= ft_strlen2(to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (ft_strlen(to_print) + 1);
	else
		my_struct.nb = my_struct.nb - ft_strlen(to_print);
	while (++i < my_struct.nb)
		ft_putchar(' ');
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	if (plus_one == 1)
		return (my_struct.nb + len_to_print + 1);
	return (my_struct.nb + len_to_print);
}

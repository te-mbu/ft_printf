/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:03:53 by tembu             #+#    #+#             */
/*   Updated: 2020/03/04 11:49:32 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			print_d_precision_minus2(t_flag my_struct,
						char *to_print, int plus_one)
{
	int i;
	int len_to_print;

	i = -1;
	len_to_print = 0;
	if (my_struct.nb <= my_struct.nb2 + ft_strlen2(to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (my_struct.nb2
		+ ft_strlen2(to_print) + 1);
	else
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(to_print));
	while (++i < my_struct.nb)
		ft_putchar(' ');
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	if (plus_one == 1)
		return (my_struct.nb + my_struct.nb2 + len_to_print + 1);
	return (my_struct.nb + my_struct.nb2 + len_to_print);
}

int					print_d_precision_minus(char *to_print, t_flag my_struct)
{
	int		i;
	int		plus_one;
	int		len_to_print;

	i = -1;
	plus_one = 0;
	len_to_print = 0;
	if (to_print[0] == '-')
	{
		min_2_plus(&to_print);
		plus_one = 1;
	}
	if (my_struct.minus2 > 0)
		return (print_d_precision_minus_sc1(my_struct, to_print, plus_one));
	if (my_struct.nb2 <= ft_strlen2(to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(to_print);
	while (++i < my_struct.nb2)
		ft_putchar('0');
	ft_putstr(to_print);
	return (print_d_precision_minus2(my_struct, to_print, plus_one));
}

int					print_d_zero(char *to_print, t_flag my_struct)
{
	int		i;
	int		plus_one;
	int		len_to_print;

	i = 0;
	plus_one = 0;
	len_to_print = 0;
	if (to_print[0] == '-' && min_2_plus(&to_print))
		plus_one = 1;
	if (my_struct.minus > 0)
		return (print_d_precision_minus_sc1(my_struct, to_print, plus_one));
	if (my_struct.nb <= ft_strlen2(to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print) + 1;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print);
	while (i++ < my_struct.nb)
		ft_putchar('0');
	ft_putstr(to_print);
	len_to_print = ft_len_to_print(&to_print);
	if (plus_one == 1)
		return (my_struct.nb + len_to_print + 1);
	return (my_struct.nb + len_to_print);
}

int					print_d_precision(char *to_print, t_flag my_struct,
					int i, int plus_one)
{
	int len_to_print;

	len_to_print = 0;
	if (is_fill_with_zero(to_print) && my_struct.nb2 == 0)
		return (ft_freeint(to_print, 0));
	if (to_print[0] == '-' && ++plus_one)
		min_2_plus(&to_print);
	if (my_struct.minus2 > 0)
	{
		ft_putstr(to_print);
		len_to_print = ft_strlen2(to_print);
		return (ft_freeint(to_print, len_to_print));
	}
	if (my_struct.nb2 <= ft_strlen2(to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(to_print);
	while (i++ < my_struct.nb2)
		ft_putchar('0');
	ft_putstr(to_print);
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	if (plus_one == 1)
		return (my_struct.nb2 + len_to_print + 1);
	return (my_struct.nb2 + len_to_print);
}

int					print_d_zero_precision_sc1(t_flag my_struct,
				char *to_print, int plus_one)
{
	int i;
	int len_to_print;

	i = -1;
	len_to_print = 0;
	if (my_struct.nb <= ft_strlen2(to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (ft_strlen2(to_print) + 1);
	else
		my_struct.nb = my_struct.nb - ft_strlen2(to_print);
	if (plus_one == 1)
		ft_putchar('-');
	while (++i < my_struct.nb)
		ft_putchar('0');
	ft_putstr(to_print);
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	if (plus_one == 1)
		return (my_struct.nb + len_to_print + 1);
	return (my_struct.nb + len_to_print);
}

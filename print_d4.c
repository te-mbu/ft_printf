/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:06:22 by tembu             #+#    #+#             */
/*   Updated: 2020/03/03 15:34:37 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int			print_d_zero_precision2(t_flag my_struct,
				char *to_print, int plus_one, char *str_precision)
{
	int i;
	int len_to_print;

	if (is_fill_with_zero(to_print) && my_struct.nb2 == 0)
		return (ft_freeint(to_print, 0, my_struct));
	if (!(i = 0) && my_struct.nb <= my_struct.nb2 + ft_strlen2(to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (my_struct.nb2
		+ ft_strlen2(to_print) + 1);
	else
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(to_print));
	if (my_struct.minus == 0)
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	if (plus_one == 1)
		ft_putchar('-');
	ft_putstr_and_free(str_precision, 0);
	len_to_print = ft_putstr_and_free(to_print, 1);
	if (my_struct.minus == 1)
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	if (plus_one == 1)
		return (my_struct.nb + my_struct.nb2 + len_to_print + 1);
	return (my_struct.nb + my_struct.nb2 + len_to_print);
}

int					print_d_zero_precision(char *to_print, t_flag my_struct,
				int i, int plus_one)
{
	char		*str_precision;

	if (to_print[0] == '-')
		to_print = min_2_plus_wo_minus(&to_print, &plus_one);
	if (is_fill_with_zero(to_print) && my_struct.nb == 0)
	{
		while (++i < my_struct.nb2)
			ft_putchar('0');
		return (ft_freeint(to_print, my_struct.nb2, my_struct));
	}
	if (my_struct.minus2 > 0 && my_struct.minus > 0)
	{
		if (plus_one == 1)
			ft_putchar('-');
		return (print_d_precision_minus_sc1(my_struct, to_print, plus_one));
	}
	if (my_struct.minus2 > 0)
		return (print_d_zero_precision_sc1(my_struct, to_print, plus_one));
	if (my_struct.nb2 <= ft_strlen2(to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(to_print);
	if (!(str_precision = (char *)malloc(sizeof(char) * (my_struct.nb2 + 1))))
		return (0);
	while (++i < my_struct.nb2)
		str_precision[i] = '0';
	str_precision[i] = '\0';
	return (print_d_zero_precision2(my_struct, to_print,
	plus_one, str_precision));
}

int					print_d_nb_and_prec_sc1(t_flag my_struct,
				char **to_print, int len_to_print)
{
	int i;

	i = 0;
	ft_putstr(*to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	len_to_print = ft_strlen2(*to_print);
	free(*to_print);
	return (my_struct.nb + ft_strlen2(*to_print));
}

int					print_d_nb_and_prec(char *to_print, t_flag my_struct)
{
	int		i;
	int		len_to_print;

	i = 0;
	len_to_print = 0;
	if (is_fill_with_zero(to_print))
	{
		while (i++ < my_struct.nb)
			ft_putchar(' ');
		free(to_print);
		return (my_struct.nb);
	}
	if (my_struct.nb <= ft_strlen2(to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print);
	if (my_struct.minus > 0)
		return (print_d_nb_and_prec_sc1(my_struct, &to_print, len_to_print));
	i = 0;
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(to_print);
	len_to_print = ft_strlen2(to_print);
	free(to_print);
	return (my_struct.nb + len_to_print);
}

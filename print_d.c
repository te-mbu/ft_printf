/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:27:59 by tembu             #+#    #+#             */
/*   Updated: 2020/03/03 22:23:48 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			print_d_spc1(char **to_print)
{
	int len_to_print;

	len_to_print = 0;
	ft_putstr(*to_print);
	len_to_print = ft_strlen2(*to_print);
	free(*to_print);
	return (len_to_print);
}

static int			print_d3(t_flag my_struct, char *to_print, int len)
{
	int len_to_print;

	len_to_print = 0;
	if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
		return (len += print_d_precision_plus(to_print, my_struct, -1, 0));
	if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
		return (len += print_d_precision_minus(to_print, my_struct));
	if (my_struct.zero == 1 && my_struct.len_nb >= 0
	&& my_struct.precision == 0)
		return (len += print_d_zero(to_print, my_struct));
	if (my_struct.minus >= 0 && my_struct.zero == 1 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
		return (len += print_d_zero_precision(to_print, my_struct, -1, 0));
	if (my_struct.len == 1 && my_struct.precision == 1)
	{
		if (is_fill_with_zero(to_print))
			return (0);
		len_to_print = ft_strlen2(to_print);
		return (ft_freeint(to_print, len_to_print));
	}
	return (len);
}

static int			print_d2(t_flag my_struct, char *to_print, int len)
{
	int i;
	int plus_one;

	i = 0;
	plus_one = 0;
	if (my_struct.minus >= 0 && my_struct.zero == 0 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.nb2 == 0 && my_struct.star2 == -1)
		return (len += (print_d_nb_and_prec(to_print, my_struct)));
	if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.nb == 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
		return (len += print_d_precision(to_print, my_struct, 0, 0));
	if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.len_nb > 0
	&& my_struct.precision == 0)
		return (len += print_d_space(to_print, my_struct));
	if (my_struct.minus > 0 && my_struct.zero == 0 && my_struct.len_nb > 0
	&& my_struct.precision == 0)
		return (len += print_d_minus_space(to_print, my_struct));
	return (print_d3(my_struct, to_print, len));
}

int					print_d(const char *str, t_flag my_struct,
					va_list args, int pos_after_percent)
{
	char	*to_print;
	size_t	len;

	len = 0;
	if (str[my_struct.len + pos_after_percent] == 'd'
	|| str[my_struct.len + pos_after_percent] == 'i')
		to_print = ft_itoa(va_arg(args, int));
	else if (str[my_struct.len + pos_after_percent] == 'u')
		to_print = ft_itoa(va_arg(args, unsigned int));
	else if (str[my_struct.len + pos_after_percent] == 'x')
		to_print = ft_itoa_base(va_arg(args, unsigned int), 16, 1);
	else if (str[my_struct.len + pos_after_percent] == 'X')
		to_print = ft_itoa_base(va_arg(args, unsigned int), 16, 2);
	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);
	if (is_fill_with_zero(to_print))
		return (ft_zero_case(my_struct, to_print, -1));
	if (my_struct.len == 0 || (my_struct.len == my_struct.minus
	&& my_struct.minus > 0 && my_struct.len_nb == 0))
		return (len += print_d_spc1(&to_print));
	return (print_d2(my_struct, to_print, len));
}

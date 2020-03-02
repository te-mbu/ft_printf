/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:18:32 by tembu             #+#    #+#             */
/*   Updated: 2020/02/29 19:32:16 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_percent_minus_zero(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		ft_putchar('%');
		my_struct.nb = my_struct.nb -= 1;
		while (i < my_struct.nb)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (my_struct.nb + 1);
}

int				print_percent_space(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		my_struct.nb = my_struct.nb -= 1;
		while (i++ < my_struct.nb)
			if (my_struct.zero > 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
		ft_putchar('%');
	}
	return (my_struct.nb + 1);
}

int				print_percent_minus_space(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		ft_putchar('%');
		my_struct.nb = my_struct.nb -= 1;
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	}
	return (my_struct.nb + 1);
}

static int		print_percent2(t_flag my_struct, int *len)
{
	if ((my_struct.len_nb > 0 && my_struct.minus == 0
	&& my_struct.precision == 0)
	|| (my_struct.len_nb > 0 && my_struct.minus == 0 && my_struct.precision == 1
	&& my_struct.len_nb2 > 0) || (my_struct.nb > 0 && my_struct.minus == 0
	&& my_struct.precision == 1 && my_struct.nb2 == 0))
		return (*len += print_percent_space(my_struct));
	else if (my_struct.minus > 0 && my_struct.nb > 0
	&& my_struct.precision == 1)
		return (*len += print_percent_minus_space(my_struct));
	else if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.nb == 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
	{
		ft_putchar('%');
		return (1);
	}
	else if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.nb == 0 &&
	my_struct.star == -1 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
	{
		ft_putchar('%');
		return (1);
	}
	return (*len);
}

int				print_percent(t_flag my_struct)
{
	int len;

	len = 0;
	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);
	if (my_struct.len == 0)
		return (len += print_percent_no_flag());
	if ((my_struct.zero > 0 && my_struct.len_nb > 0 && my_struct.minus == 0
	&& my_struct.precision == 0 && my_struct.nb2 == 0))
		return (len += print_percent_zero(my_struct));
	if ((my_struct.minus > 0 && my_struct.len_nb > 0
	&& my_struct.precision == 0))
		return (len += print_percent_minus_zero(my_struct));
	return (print_percent2(my_struct, &len));
}

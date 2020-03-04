/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:25:35 by tembu             #+#    #+#             */
/*   Updated: 2020/03/04 11:49:04 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_zero_case5(t_flag my_struct, int plus_one,
					int minus2changed, int i)
{
	if ((my_struct.zero > 0 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0
	&& my_struct.len == 4))
	{
		if (minus2changed == 1)
			return (ft_zero_case5_sc1(my_struct, i));
		my_struct.nb = (my_struct.nb <= my_struct.nb2) ?
		0 : my_struct.nb - my_struct.nb2;
		if (plus_one == 0)
			while (++i < my_struct.nb)
				ft_putchar(' ');
		i = 0;
		while (i++ < my_struct.nb2)
			ft_putchar('0');
		i = 0;
		if (plus_one == 1)
			while (i++ < my_struct.nb)
				ft_putchar(' ');
		return (my_struct.nb + my_struct.nb2);
	}
	return (ft_zero_case6(my_struct, i));
}

static int			ft_zero_case4(t_flag my_struct, int plus_one,
					int minus2changed, int i)
{
	if ((my_struct.len_nb > 0 && my_struct.precision == 1
		&& my_struct.len_nb2 > 0 && my_struct.len == 3)
		|| (my_struct.len_nb > 0 && my_struct.precision == 1
		&& my_struct.len_nb2 > 0 && my_struct.minus > 0
		&& my_struct.len - (my_struct.minus - 1) == 4))
	{
		if (my_struct.minus > 0)
			plus_one = 1;
		my_struct.nb = (my_struct.nb <= my_struct.nb2) ?
		0 : my_struct.nb - my_struct.nb2;
		if (plus_one == 0)
			while (++i < my_struct.nb)
				ft_putchar(' ');
		i = 0;
		while (i++ < my_struct.nb2)
			ft_putchar('0');
		i = 0;
		if (plus_one == 1)
			while (i++ < my_struct.nb)
				ft_putchar(' ');
		return (my_struct.nb + my_struct.nb2);
	}
	return (ft_zero_case5(my_struct, plus_one, minus2changed, i));
}

static int			ft_zero_case3(t_flag my_struct, int plus_one,
					int minus2changed, int i)
{
	if (my_struct.zero > 0 && my_struct.len_nb > 0
			&& my_struct.precision == 0)
	{
		if (my_struct.nb == 0)
		{
			ft_putchar('0');
			return (1);
		}
		while (++i < my_struct.nb)
			ft_putchar('0');
		return (my_struct.nb);
	}
	else if ((my_struct.zero == 0 && my_struct.len_nb > 0
			&& my_struct.precision == 1 && my_struct.len == 2
			&& my_struct.len_nb2 == 0) || (my_struct.minus > 0
			&& my_struct.len > 0 && my_struct.precision == 1
			&& my_struct.len - (my_struct.minus - 1) == 3
			&& my_struct.len_nb2 == 0))
	{
		while (++i < my_struct.nb)
			ft_putchar(' ');
		return (my_struct.nb);
	}
	return (ft_zero_case4(my_struct, plus_one, minus2changed, i));
}

static int			ft_zero_case2(t_flag my_struct, int plus_one,
					int minus2changed, int i)
{
	if ((my_struct.len == 1 && my_struct.len_nb > 0
				&& my_struct.precision == 0) || (my_struct.minus > 0 &&
				my_struct.len_nb > 0 && my_struct.precision == 0))
	{
		if (my_struct.minus > 0)
			plus_one = 1;
		my_struct.nb = (my_struct.nb <= 1) ? 0 : my_struct.nb - 1;
		if (plus_one == 1)
			ft_putchar('0');
		while (++i < my_struct.nb)
			ft_putchar(' ');
		if (plus_one == 0)
			ft_putchar('0');
		return (my_struct.nb + 1);
	}
	return (ft_zero_case3(my_struct, plus_one, minus2changed, i));
}

int					ft_zero_case(t_flag my_struct, char *to_print, int i)
{
	int plus_one;
	int minus2changed;

	plus_one = 0;
	minus2changed = 0;
	free(to_print);
	if (my_struct.minus2 > 0)
	{
		my_struct.nb2 = 1;
		my_struct.minus2 = 0;
		minus2changed = 1;
	}
	if (my_struct.len == 0)
	{
		ft_putchar('0');
		return (1);
	}
	return (ft_zero_case2(my_struct, plus_one, minus2changed, i));
}

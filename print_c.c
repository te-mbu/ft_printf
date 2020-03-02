/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:25:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/29 18:04:48 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_c_no_flag(char tmp)
{
	ft_putchar(tmp);
	return (1);
}

int				print_c_space(char tmp, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar(tmp);
		return (1);
	}
	else
	{
		my_struct.nb = my_struct.nb -= 1;
		while (i < my_struct.nb)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar(tmp);
		return (my_struct.nb + 1);
	}
}

int				print_c_minus_space(char tmp, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar(tmp);
		return (1);
	}
	else
	{
		my_struct.nb = my_struct.nb -= 1;
		ft_putchar(tmp);
		while (i < my_struct.nb)
		{
			ft_putchar(' ');
			i++;
		}
		return (my_struct.nb + 1);
	}
}

int				print_c(t_flag my_struct, va_list args)
{
	char	tmp;
	size_t	len;

	len = 0;
	tmp = va_arg(args, int);
	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);
	if (my_struct.len == 0)
		len += print_c_no_flag(tmp);
	else if (my_struct.minus == 0)
		len += print_c_space(tmp, my_struct);
	else if (my_struct.minus > 0)
		len += print_c_minus_space(tmp, my_struct);
	return (len);
}

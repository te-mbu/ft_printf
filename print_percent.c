/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:18:32 by tembu             #+#    #+#             */
/*   Updated: 2020/02/19 20:18:39 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_percent_no_flag()
{
	ft_putchar('%');
	return (1);
}

int				print_percent_space(const char *str, int pos_after_percent)
{
	size_t nb_space;
	size_t i;

	nb_space = 0;
	i = 0;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	nb_space = nb_space - 1;
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('%');
	return (nb_space + 1);
}

int				print_percent_minus_space(const char *str, int pos_after_percent)
{
	size_t nb_space;
	size_t i;

	nb_space = 0;
	i = 0;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	ft_putchar('%');
	nb_space = nb_space - 1;
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	return (nb_space + 1);
}

int				print_percent_zero(const char *str, int pos_after_percent)
{
	size_t nb_zero;
	size_t i;

	nb_zero = 0;
	i = 0;
	while (str[pos_after_percent] == '0')
		pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_zero = nb_zero * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	nb_zero = nb_zero - 1;
	while (i < nb_zero)
	{
		ft_putchar('0');
		i++;
	}
	ft_putchar('%');
	return (nb_zero + 1);
}

int				print_percent_minus_zero(const char *str, int pos_after_percent)
{
	size_t nb_zero;
	size_t i;

	nb_zero = 0;
	i = 0;
	pos_after_percent++;
	while (str[pos_after_percent] == '0')
		pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_zero = nb_zero * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	nb_zero = nb_zero - 1;
	ft_putchar('%');
	while (i < nb_zero)
	{
		ft_putchar(' ');
		i++;
	}
	return (nb_zero + 1);
}

int				print_percent(const char *str, t_flag my_struct, int pos_after_percent)
{
	size_t len;

	len = 0;
	if ((my_struct.zero > 0 && my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 0 
					&& my_struct.nb2 == 0))
		len += print_percent_zero(str, pos_after_percent);
	else if ((my_struct.nb > 0 && my_struct.minus == 1 && my_struct.precision == 0 && my_struct.nb2 == 0))
		len += print_percent_minus_zero(str, pos_after_percent);
	else if ((my_struct.nb == 0 && my_struct.minus == 0 && my_struct.precision == 0 && my_struct.nb2 == 0)
		|| (my_struct.nb == 0 && my_struct.minus == 0 && my_struct.precision == 1 && my_struct.nb2 == 0) 
			|| (my_struct.nb == 0 && my_struct.precision == 1 && my_struct.nb2 > 0))
		len += print_percent_no_flag();
	else if ((my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 0 && my_struct.nb2 == 0)
		|| (my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 1 && my_struct.nb2 > 0)
			|| (my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 1 && my_struct.nb2 == 0))
		len += print_percent_space(str, pos_after_percent);
	else if ((my_struct.minus == 1 && my_struct.nb > 0 && my_struct.precision == 0) 
		||(my_struct.minus == 1 && my_struct.nb > 0 && my_struct.precision == 1))
		len += print_percent_minus_space(str, pos_after_percent);
	return (len);
}
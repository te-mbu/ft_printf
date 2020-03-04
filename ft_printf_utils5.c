/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:46:05 by tembu             #+#    #+#             */
/*   Updated: 2020/03/04 11:47:51 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_len_to_print(char **to_print)
{
	int len_to_print;

	len_to_print = ft_strlen2(*to_print);
	free(*to_print);
	return (len_to_print);
}

int					print_s_space(char *to_print, t_flag my_struct)
{
	int i;
	int len_to_print;

	i = 0;
	len_to_print = 0;
	if (my_struct.nb <= ft_strlen2(to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(to_print);
	len_to_print = ft_strlen(to_print);
	free(to_print);
	return (my_struct.nb + len_to_print);
}

int					ft_freeint(char *str, int ret)
{
	free(str);
	return (ret);
}

int					ft_zero_case6(t_flag my_struct, int i)
{
	if ((my_struct.precision == 1 && my_struct.len_nb2 > 0
	&& my_struct.len == 2)
	|| (my_struct.minus > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0
	&& my_struct.len - (my_struct.minus - 1) == 3))
	{
		if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.len_nb > 0
		&& my_struct.precision == 1 && my_struct.len == 2 && my_struct.nb2 == 0)
		{
			while (++i < my_struct.nb)
				ft_putchar(' ');
			return (my_struct.nb);
		}
		while (++i < my_struct.nb2)
			ft_putchar('0');
		return (my_struct.nb2);
	}
	return (0);
}

int					ft_zero_case5_sc1(t_flag my_struct, int i)
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

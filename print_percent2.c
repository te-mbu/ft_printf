/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:58:13 by tembu             #+#    #+#             */
/*   Updated: 2020/02/29 18:14:06 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_percent_zero(t_flag my_struct)
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
		while (i < my_struct.nb)
		{
			ft_putchar('0');
			i++;
		}
		ft_putchar('%');
	}
	return (my_struct.nb + 1);
}

int				print_percent_no_flag(void)
{
	ft_putchar('%');
	return (1);
}

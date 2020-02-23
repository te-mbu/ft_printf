/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:25:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/23 13:24:53 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//PRINTF("%c", 'a');
int				print_c_no_flag(char tmp)
{
	ft_putchar(tmp);
	return (1);
}

//PRINTF("%5c", 'a')

int			print_c_space(const char *str, int pos_after_percent, char tmp)
{
	size_t nb_space;
	size_t i;
	int plus_one;

	nb_space = 0;
	i = 0;
	plus_one = 0;
	nb_space = small_atoi(str, &pos_after_percent, nb_space);
	if (nb_space > 1)
	{
		nb_space = nb_space - 1;
		plus_one = 1;
	}
	else
		nb_space = 0;
		
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(tmp);
	if (plus_one == 1)
		return (nb_space + 1);
	return (nb_space);
}

//PRINTF("%-15c", 'a');
int			print_c_minus_space(const char *str, int pos_after_percent, char tmp)
{
	size_t nb_space;
	size_t i;
	int plus_one;

	nb_space = 0;
	i = 0;
	plus_one = 0;
	pos_after_percent++;
	nb_space = small_atoi(str, &pos_after_percent, nb_space);
	if (nb_space > 1)
	{
		nb_space = nb_space - 1;
		plus_one = 1;
	}
	else
		nb_space = 0;
	ft_putchar(tmp);
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	if (plus_one == 1)
		return (nb_space + 1);
	return (nb_space);
}

int				print_c(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	tmp;
	size_t len;

	len = 0;
	tmp = va_arg(args, int);

	if (my_struct.nb == 0 && my_struct.minus == 0)
		len += print_c_no_flag(tmp);
	else if (my_struct.nb == 1 && my_struct.minus == 0)
		len += print_c_space(str, pos_after_percent, tmp);
	else if (my_struct.nb == 1 && my_struct.minus == 1)
		len += print_c_minus_space(str, pos_after_percent, tmp);
	return (len);
}
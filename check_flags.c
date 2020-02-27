/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:07:20 by tembu             #+#    #+#             */
/*   Updated: 2020/02/27 17:27:42 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_flag_zero(const char *str, t_flag *my_struct, int *i)
{
	if (str[*i] == '0')
	{
		my_struct->zero = 1;
		my_struct->len += 1;
		*i += 1;
	}
}

void			check_flag_nb_minus_star(const char *str, t_flag *my_struct, va_list args,  int *i)
{	
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-' ||
						str[*i] == '*')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				my_struct->nb = my_struct->nb * 10 + str[*i] - 48;
				*i += 1;
			}
			my_struct->len += 1;
			my_struct->len_nb = len_ofnumber(my_struct->nb);
		}
		if (str[*i] == '-')
		{
			my_struct->minus += 1;
			my_struct->len += 1;
			*i += 1;
		}
		if (str[*i] == '*')
		{
			my_struct->star = va_arg(args, int);
			my_struct->len_star = len_ofnumber(my_struct->star);
			if (my_struct->star < 0)
			{
				my_struct->star *= (-1);
				my_struct->minus = 1;
			}
			my_struct->len += 1;
			*i += 1;
		}
	}
}

void			check_flag_precision(const char *str, t_flag *my_struct, int *i)
{
	if (str[*i] == '.')
	{
		my_struct->precision = 1;
		my_struct->len += 1;
		*i += 1;
	}
}

void			check_flag_nb2_minus2_star2(const char *str, t_flag *my_struct, va_list args, int *i)
{
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-' || str[*i] == '*')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				my_struct->nb2 = my_struct->nb2 * 10 + str[*i] - 48;
				*i += 1;
			}
			my_struct->len += 1;
			my_struct->len_nb2 = len_ofnumber(my_struct->nb2);
		}
		if (str[*i] == '-')
		{
			my_struct->minus2 += 1;
			my_struct->len += 1;
			*i += 1;
		}
		if (str[*i] == '*')
		{
			my_struct->star2 = va_arg(args, int);
			my_struct->len_star2 = len_ofnumber(my_struct->star2);
			if (my_struct->star2 < 0)
			{
				my_struct->star2 *= (-1);
				my_struct->minus2 = 1;
			}
			my_struct->len += 1;
			*i += 1;
		}
	}
}
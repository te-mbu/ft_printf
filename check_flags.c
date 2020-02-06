/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:07:20 by tembu             #+#    #+#             */
/*   Updated: 2020/02/05 17:16:18 by tembu            ###   ########.fr       */
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

void			check_flag_nb_minus_star(const char *str, t_flag *my_struct, int *i)
{
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-' || str[*i] == '*')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			my_struct->nb += 1;
			my_struct->len += 1;
			*i += 1;
		}
		if (str[*i] == '-')
		{
			my_struct->minus += 1;
			my_struct->len += 1;
			*i += 1;
		}
		if (str[*i] == '*')
		{
			my_struct->star += 1;
			my_struct->len += 1;
			*i += 1;
		}
	}
}

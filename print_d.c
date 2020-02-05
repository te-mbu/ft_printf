/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:27:59 by tembu             #+#    #+#             */
/*   Updated: 2020/02/05 19:11:35 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_d(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*to_print;
	int 	nb_zero;
	size_t	len;

	nb_zero = 0;
	to_print = ft_strdup(ft_itoa(va_arg(args, int)));
	if (my_struct.zero == 1)
	{
		pos_after_percent++;
		while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9'))
		{
			nb_zero = nb_zero * 10 + str[pos_after_percent] - 48;
			pos_after_percent++;
		}
		nb_zero = nb_zero - ft_strlen(to_print);

	}

	ft_putstr(to_print);
	len = ft_strlen(to_print);
	free(to_print);
	return (len);
}
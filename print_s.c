/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:16:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/29 19:32:31 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_s_minus_space_precision(char **to_print, t_flag my_struct)
{
	int		i;

	i = -1;
	if (my_struct.minus > 0 && my_struct.minus2 > 0)
		return (print_s_minus_space_precision_sc1(my_struct, &*to_print));
	if (my_struct.minus2 > 0)
	{
		ft_putstr(*to_print);
		return (ft_strlen(*to_print));
	}
	if (my_struct.nb2 >= ft_strlen2(*to_print))
	{
		my_struct.nb2 = ft_strlen(*to_print);
		ft_putstr(*to_print);
	}
	else
		while (++i < my_struct.nb2)
			ft_putchar(to_print[0][i]);
	i = 0;
	my_struct.nb = (my_struct.nb <= my_struct.nb2) ?
	0 : my_struct.nb - my_struct.nb2;
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	return (my_struct.nb + my_struct.nb2);
}

int				print_s_precision(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.minus2 > 0)
	{
		ft_putstr(*to_print);
		return (ft_strlen(*to_print));
	}
	if (my_struct.nb2 >= ft_strlen2(*to_print))
	{
		my_struct.nb2 = ft_strlen2(*to_print);
		ft_putstr(*to_print);
		return (ft_strlen2(*to_print));
	}
	else
		while (i < my_struct.nb2)
		{
			ft_putchar(to_print[0][i]);
			i++;
		}
	return (my_struct.nb2);
}

int				print_s_nb_prec_only(t_flag my_struct)
{
	int i;

	i = 0;
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	return (my_struct.nb);
}

static int		print_s2(t_flag my_struct, int *len, char *to_print)
{
	if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.len_nb > 0
	&& my_struct.precision == 0)
		return (*len += print_s_space(to_print, my_struct));
	if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb > 0
	&& my_struct.precision == 0)
		return (*len += print_s_minus_space(to_print, my_struct));
	if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.nb == 0
	&& my_struct.len_nb2 > 0 && my_struct.precision == 1)
		return (*len += print_s_precision(&to_print, my_struct));
	if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
		return (*len += print_s_space_precision(&to_print, my_struct));
	if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb > 0
	&& my_struct.precision == 1 && my_struct.len_nb2 > 0)
		return (*len += print_s_minus_space_precision(&to_print, my_struct));
	return (*len);
}

int				print_s(t_flag my_struct, va_list args)
{
	char	*to_print;
	int		len;

	len = 0;
	to_print = ft_strdup(va_arg(args, char *));
	if (to_print == NULL)
	{
		free(to_print);
		to_print = ft_strdup("(null)");
	}
	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);
	if (my_struct.len == 0 || (my_struct.len == my_struct.minus
	&& my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb == 0
	&& my_struct.precision == 0 && my_struct.len_nb2 == 0))
		return (len += print_and_return_size(&to_print));
	if ((my_struct.zero == 0 && my_struct.minus >= 0 && my_struct.nb > 0
	&& my_struct.precision == 1 && my_struct.star2 == -1 && my_struct.nb2 == 0))
		return (len += print_s_nb_prec_only(my_struct));
	return (print_s2(my_struct, &len, to_print));
}

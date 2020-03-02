/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:53:30 by tembu             #+#    #+#             */
/*   Updated: 2020/02/29 18:33:18 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_s_minus_space(char *to_print, t_flag my_struct)
{
	int i;
	int len_to_print;

	i = 0;
	len_to_print = 0;
	if (my_struct.nb <= ft_strlen2(to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(to_print);
	ft_putstr(to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	len_to_print = ft_strlen(to_print);
	free(to_print);
	return (my_struct.nb + len_to_print);
}

int				print_s_space_precision_sc1(char **to_print,
				t_flag my_struct)
{
	int i;
	int len_to_print;

	i = -1;
	len_to_print = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen(*to_print);
	while (++i < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(*to_print);
	len_to_print = ft_strlen2(*to_print);
	free(*to_print);
	return (my_struct.nb + len_to_print);
}

static int		print_s_space_precision2(t_flag my_struct,
				char **str_prec, char **to_print)
{
	int i;

	i = 0;
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(*str_prec);
	free(*str_prec);
	free(*to_print);
	return (my_struct.nb + my_struct.nb2);
}

int				print_s_space_precision(char **to_print, t_flag my_struct)
{
	int		i;
	char	*str_prec;

	i = -1;
	if (my_struct.minus2 > 0)
		return (print_s_space_precision_sc1(&*to_print, my_struct));
	if (my_struct.nb2 >= ft_strlen2(*to_print))
	{
		my_struct.nb2 = ft_strlen2(*to_print);
		str_prec = ft_strdup(*to_print);
	}
	else
	{
		if (!(str_prec = (char *)malloc(sizeof(char) * (my_struct.nb2) + 1)))
			return (0);
		while (++i < my_struct.nb2)
			str_prec[i] = to_print[0][i];
		str_prec[i] = '\0';
	}
	i = 0;
	my_struct.nb = (my_struct.nb <= ft_strlen2(str_prec)) ?
	0 : my_struct.nb - ft_strlen(str_prec);
	return (print_s_space_precision2(my_struct, &str_prec, &*to_print));
}

int				print_s_minus_space_precision_sc1(t_flag my_struct,
				char **to_print)
{
	int i;
	int len_to_print;

	i = -1;
	len_to_print = 0;
	ft_putstr(*to_print);
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb - ft_strlen(*to_print);
	while (++i < my_struct.nb)
		ft_putchar(' ');
	len_to_print = ft_strlen2(*to_print);
	return (my_struct.nb + ft_strlen(*to_print));
}

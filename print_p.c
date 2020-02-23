/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:07:36 by tembu             #+#    #+#             */
/*   Updated: 2020/02/21 12:52:11 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_p_space(const char *str, int pos_after_percent, char **to_print)
{
	size_t nb_space;
	size_t i;

	i = 0;
	nb_space = 0;
	nb_space = small_atoi(str, &pos_after_percent, nb_space);
	if (nb_space <= ft_strlen(*to_print))
		nb_space = 0;
	else
		nb_space = nb_space - ft_strlen(*to_print);
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(*to_print);
	return (nb_space + ft_strlen(*to_print));
}

int				print_p_minus_space(const char *str, int pos_after_percent, char **to_print)
{
	size_t nb_space;
	size_t i;

	i = 0;
	nb_space = 0;
	pos_after_percent++;
	nb_space = small_atoi(str, &pos_after_percent, nb_space);
	if (nb_space <= ft_strlen(*to_print))
		nb_space = 0;
	else
		nb_space = nb_space - ft_strlen(*to_print);
	ft_putstr(*to_print);
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	return (nb_space + ft_strlen(*to_print));
}

int				print_p(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*tmp;
	char	*tmp2;
	char	*to_print;
	size_t	len;

	len = 0;
	if (!(tmp = ft_strdup("0x")))
		return (0);
	if (!(tmp2 = ft_itoa_base_p((unsigned long)va_arg(args, void*), 16, 1)))
		return (0);
	if (!(to_print = ft_strjoin(tmp, tmp2)))
		return (0);
	free(tmp);
	free(tmp2);

	if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.nb == 0 && my_struct.precision == 0)
	{
		ft_putstr(to_print);
		len += ft_strlen(to_print);
	}

		//PRINTF("%5p", 12);
	else if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.nb > 0 && my_struct.precision == 0)
		len += print_p_space(str, pos_after_percent, &to_print);

		//PRINTF("%-5d", 12);
	else if (my_struct.minus == 1 && my_struct.zero == 0 && my_struct.nb > 0 
			&& my_struct.precision == 0)
		len += print_p_minus_space(str, pos_after_percent, &to_print);

	free(to_print);
	return (len);
}

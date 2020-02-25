/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:07:36 by tembu             #+#    #+#             */
/*   Updated: 2020/02/26 00:17:32 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_p_space(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct. nb = my_struct.nb -= ft_strlen2(*to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(*to_print);
	return (my_struct.nb + ft_strlen(*to_print));
}

int				print_p_minus_space(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct. nb = my_struct.nb -= ft_strlen2(*to_print);
	ft_putstr(*to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	return (my_struct.nb + ft_strlen(*to_print));
}

int				print_p(t_flag my_struct, va_list args)
{
	char	*tmp;
	char	*tmp2;
	char	*to_print;
	int	len;

	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);

	len = 0;
	if (!(tmp = ft_strdup("0x")))
		return (0);
	if (!(tmp2 = ft_itoa_base_p((unsigned long)va_arg(args, void*), 16, 1)))
		return (0);
	if (!(to_print = ft_strjoin(tmp, tmp2)))
		return (0);
	free(tmp);
	free(tmp2);

	if (my_struct.len == 0)
	{
		ft_putstr(to_print);
		len += ft_strlen(to_print);
	}

		//PRINTF("%5p", 12);
	else if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.len_nb > 0 && my_struct.precision == 0)
		len += print_p_space(&to_print, my_struct);

		//PRINTF("%-5d", 12);
	else if (my_struct.minus > 0 && my_struct.zero == 0 && my_struct.len_nb > 0 
			&& my_struct.precision == 0)
		len += print_p_minus_space(&to_print, my_struct);

	free(to_print);
	return (len);
}

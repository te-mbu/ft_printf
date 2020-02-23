/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:09:07 by tembu             #+#    #+#             */
/*   Updated: 2020/02/23 14:29:27 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_parsing(const char *str, t_flag *my_struct, int *i)
{
	*i += 1;
	check_flag_zero(str, &*my_struct, &*i);
	check_flag_nb_minus_star(str, &*my_struct, &*i);
	check_flag_precision(str, &*my_struct, &*i);
	check_flag_nb2_minus2_star2(str, &*my_struct, &*i);
}

int			ft_conversion(const char *str, t_flag my_struct, va_list args, int *i)
{
	int pos_after_percent;

	pos_after_percent = *i - my_struct.len;
	if (*i >= (int)ft_strlen(str))
		return (0);
	if (str[*i] == 's')
		return (print_s(str, my_struct, args, pos_after_percent));
	else if (str[*i] == 'c')
		return (print_c(str, my_struct, args, pos_after_percent));
	else if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u'
			|| str[*i] == 'x' || str[*i] == 'X')
		return (print_d(str, my_struct, args, pos_after_percent));
	else if (str[*i] == 'p')
		return (print_p(str, my_struct, args, pos_after_percent));	
	else if (str[*i] == '%')
		return (print_percent(str, my_struct, pos_after_percent));
	return (0);
}

void		ft_init_list(t_flag *my_struct)
{
	my_struct->zero = 0;
	my_struct->minus = 0;
	my_struct->minus2 = 0;
	my_struct->nb = 0;
	my_struct->nb2 = 0;
	my_struct->star = 0;
	my_struct->star2 = 0;
	my_struct->precision = 0;
	my_struct->len = 0;
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int			i;
	t_flag		my_struct;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_init_list(&my_struct);
			ft_parsing(str, &my_struct, &i);
//			printf("\n\n\nstruct.zero : %d\n", my_struct.zero);
//			printf("struct.minus : %d\n", my_struct.minus);
//			printf("struct.minus 2: %d\n", my_struct.minus2);
//			printf("struct.nb : %d\n", my_struct.nb);
//			printf("struct.nb 2: %d\n", my_struct.nb2);
//			printf("struct.precision : %d\n", my_struct.precision);
//			printf("struct.len : %d\n", my_struct.len);
			len += ft_conversion(str, my_struct, args, &i);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

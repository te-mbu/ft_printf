/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:09:07 by tembu             #+#    #+#             */
/*   Updated: 2020/02/05 19:01:08 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_parsing(const char *str, t_flag *my_struct, int *i)
{
	int pos_pourcent;

	pos_pourcent = *i;
	*i += 1;
	check_flag_zero(str, &*my_struct, &*i);
	check_flag_nb_minus_star(str, &*my_struct, &*i);
}

int			ft_conversion(const char *str, t_flag my_struct, va_list args, int *i)
{
	//*i += 1;
	//printf("\n\npos : %d | %c\n\n", *i, str[*i]);
	int pos_after_percent;

	pos_after_percent = *i;

	if (str[*i] == 's')
		return (print_s(my_struct, args));
	if (str[*i] == 'd')
		return (print_d(str, my_struct, args, pos_after_percent));
	return (0);
}

void		ft_init_list(t_flag *my_struct)
{
	my_struct->zero = 0;
	my_struct->minus = 0;
	my_struct->nb = 0;
	my_struct->star = 0;
	my_struct->dot = 0;
	my_struct->len = 0;
}

int				ft_printf(const char *str, ...)
{
	va_list			args;
	int			len;
	int			i;
	t_flag			my_struct;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		ft_init_list(&my_struct);
		if (str[i] == '%')
		{
			ft_parsing(str, &my_struct, &i);
			//printf("\n\n\nstruct.zero : %d\n", my_struct.zero);
			//printf("struct.minus : %d\n", my_struct.minus);
			//printf("struct.nb : %d\n", my_struct.nb);
			//printf("struct.dot : %d\n", my_struct.dot);
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

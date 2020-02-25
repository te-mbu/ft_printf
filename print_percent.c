/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:18:32 by tembu             #+#    #+#             */
/*   Updated: 2020/02/25 17:31:21 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//good
int				print_percent_no_flag()
{
	ft_putchar('%');
	return (1);
}

//PRINTF("%05%");			good
//PRINTF("%0*%", 5);		good
int				print_percent_zero(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		my_struct.nb = my_struct.nb -= 1;
		while (i < my_struct.nb)
		{
			ft_putchar('0');
			i++;
		}
		ft_putchar('%');
	}
	return (my_struct.nb + 1);
}

//PRINTF("%-5%");			good
//PRINTF("%*%", -5);		good
//PRINTF("%-*%", 5);		good
int				print_percent_minus_zero(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		ft_putchar('%');
		my_struct.nb = my_struct.nb -= 1;
		while (i < my_struct.nb)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (my_struct.nb + 1);
}

//PRINTF("%5%");			good
//PRINTF("%*%", 5);			good
int				print_percent_space(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		my_struct.nb = my_struct.nb -= 1;
		while (i < my_struct.nb)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('%');
	}
	return (my_struct.nb + 1);
}

//PRINTF("%5.%");			good
//PRINTF("%*.%", 5);		good
//PRINTF("%-*.%", 5);		good
int				print_percent_minus_space(t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= 1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		ft_putchar('%');
		my_struct.nb = my_struct.nb -= 1;
		while (i < my_struct.nb)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (my_struct.nb + 1);
}


int				print_percent(t_flag my_struct)
{
	size_t len;

	len = 0;

	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;	
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);

//PRINTF("%%");
	if (my_struct.len == 0)
		len += print_percent_no_flag();

//PRINTF("%05%");
//PRINTF("%0*%", 5);
	else if ((my_struct.zero > 0 && my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 0 
					&& my_struct.nb2 == 0))
		len += print_percent_zero(my_struct);

//PRINTF("%-5%");
//PRINTF("%*%", -5);
//PRINTF("%-*%", 5);
	else if ((my_struct.minus > 0 && my_struct.nb > 0 && my_struct.precision == 0 && my_struct.len_nb2 == 0))
		len += print_percent_minus_zero(my_struct);

//PRINTF("%5%");
//PRINTF("%*%", 5);
	else if ((my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 0 && my_struct.nb2 == 0)
		|| (my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 1 && my_struct.nb2 > 0)
			|| (my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 1 && my_struct.nb2 == 0))
		len += print_percent_space(my_struct);

//PRINTF("%5.%");
//PRINTF("%*.%", 5);
//PRINTF("%-*.%", 5);
	else if ((my_struct.minus > 0 && my_struct.nb > 0 && my_struct.precision == 1))
		len += print_percent_minus_space(my_struct);

	return (len);
}
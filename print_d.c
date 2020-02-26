/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:27:59 by tembu             #+#    #+#             */
/*   Updated: 2020/02/26 04:54:44 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//PRINTF("%5d", 12);		good
int				print_d_space(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
	{
		my_struct.nb = 0;
		ft_putstr(*to_print);
	}
	else
	{
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print);
		while (i++ < my_struct.nb)
			ft_putchar(' ');
		ft_putstr(*to_print);
	}
	return (my_struct.nb + ft_strlen2(*to_print));
}

//PRINTF("%-5d", 12);		good
int				print_d_minus_space(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
	{
		my_struct.nb = 0;
		ft_putstr(*to_print);
	}
	else
	{
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print);
		ft_putstr(*to_print);
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	}
	return (my_struct.nb + ft_strlen2(*to_print));
}

//PRINTF("%5.2d", 12)		good
//PRINTF("%*.*d", 5, 3, 12)	good
int				print_d_precision_plus(char **to_print, t_flag my_struct)
{
	int			i;
	int			plus_one;
	long long 	result;
	char		*str_precision;

	i = -1;
	plus_one = 0;

	if (to_print[0][0] == '-')
	{
		result = ft_atoi(*to_print) * (-1);
		free(*to_print);
		*to_print = ft_itoa(result);
		plus_one = 1;
	}
	if (my_struct.nb2 <= ft_strlen2(*to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(*to_print);
	if (!(str_precision = (char *)malloc(sizeof(char) * (my_struct.nb2 + 1))))
		return (0);
	while (++i < my_struct.nb2)
		str_precision[i] = '0';
	i = 0;
	if (my_struct.nb <= my_struct.nb2 + ft_strlen2(*to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(*to_print) + 1);
	else
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(*to_print));
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	if (plus_one == 1)
		ft_putchar('-');
	ft_putstr(str_precision);
	free(str_precision);
	ft_putstr(*to_print);
	if (plus_one == 1)
		return (my_struct.nb + my_struct.nb2 + ft_strlen(*to_print) + 1);
	return (my_struct.nb + my_struct.nb2 + ft_strlen(*to_print));
}

//PRINTF("%-5.2d", 12)			good
//PRINTF("%-*.*d", 5, 3, 12)	good
int				print_d_precision_minus(char **to_print, t_flag my_struct)
{
	int 	i;
	int 	plus_one;

	i = -1;
	plus_one = 0;
	if (to_print[0][0] == '-')
	{
		min_2_plus(&*to_print);
		plus_one = 1;
	}
	if (my_struct.minus2 > 0)
	{
		ft_putstr(*to_print);
		if (my_struct.nb <= ft_strlen2(*to_print))
			my_struct.nb = 0;
		else if (plus_one == 1)
			my_struct.nb = my_struct.nb - (ft_strlen(*to_print) + 1);
		else
			my_struct.nb = my_struct.nb - ft_strlen(*to_print);
		while(++i < my_struct.nb)
			ft_putchar(' ');
		if (plus_one == 1)
			return (my_struct.nb + ft_strlen(*to_print) + 1);
		return (my_struct.nb + ft_strlen(*to_print));
	}
	if (my_struct.nb2 <= ft_strlen2(*to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen(*to_print);
	while (++i < my_struct.nb2)
		ft_putchar('0');
	ft_putstr(*to_print);
	i = -1;
	if (my_struct.nb <= my_struct.nb2 + ft_strlen2(*to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen(*to_print) + 1);
	else
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen(*to_print));
	while (++i < my_struct.nb)
		ft_putchar(' ');
	if (plus_one == 1)
		return (my_struct.nb + my_struct.nb2 + ft_strlen(*to_print) + 1);
	return (my_struct.nb + my_struct.nb2 + ft_strlen(*to_print));
}


//PRINTF("%015", 12);			good
int				print_d_zero(char **to_print, t_flag my_struct)
{
	int 	i;
	int 	plus_one;

	i = 0;
	plus_one = 0;

	if (to_print[0][0] == '-')
	{
		min_2_plus(&*to_print);
		plus_one = 1;
	}
	if (my_struct.minus > 0)
	{
		if (my_struct.nb <= ft_strlen2(*to_print))
			my_struct.nb = 0;
		else if (plus_one == 1)
			my_struct.nb = my_struct.nb - (ft_strlen(*to_print) + 1);
		else
			my_struct.nb = my_struct.nb -= ft_strlen(*to_print);
		ft_putstr(*to_print);
		while (i++ < my_struct.nb)
			ft_putchar(' ');
			i++;
		if (plus_one == 1)
			return (my_struct.nb + ft_strlen(*to_print) + 1);
		return (my_struct.nb + ft_strlen(*to_print));
	}
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print) + 1;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print);
	while (i++ < my_struct.nb)
		ft_putchar('0');
	ft_putstr(*to_print);
	if (plus_one == 1)
		return (my_struct.nb + ft_strlen(*to_print) + 1);
	return (my_struct.nb + ft_strlen(*to_print));
}

//PRINTF("%.5d", 12);
int				print_d_precision(char **to_print, t_flag my_struct)
{
	int i;
	int plus_one;

	i = 0;
	plus_one = 0;
	if (to_print[0][0] == '-')
	{
		min_2_plus(&*to_print);
		plus_one = 1;
	}
	if (my_struct.nb2 <= ft_strlen2(*to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(*to_print);
	while (i++ < my_struct.nb2)
		ft_putchar('0');
	ft_putstr(*to_print);
	if (plus_one == 1)
		return (my_struct.nb2 + ft_strlen(*to_print) + 1);
	return (my_struct.nb2 + ft_strlen(*to_print));
}

/*
int				ft_input_equal_zero(const char *str, int pos_after_percent, t_flag my_struct)
{
	size_t nb_space;
	size_t i;

	nb_space = 0;
	i = 0;
	if (my_struct.nb == 0)
		return (0);
	if (my_struct.minus == 1)
		pos_after_percent++;
	nb_space = small_atoi_final(str, &pos_after_percent, nb_space, my_struct);
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	return (nb_space);
}
*/

//PRINTF("%08.5d", 34);
//PRINTF("%0*.5d", 8, 34);
int				print_d_zero_precision(char **to_print, t_flag my_struct)
{
	int 		i;
	int			plus_one;
	long long	result;
	char		*str_precision;
	i = -1;
	plus_one = 0;
	result = 0;

	if (to_print[0][0] == '-')
	{
		result = ft_atoi(*to_print) * (-1);
		free(*to_print);
		*to_print = ft_itoa(result);
		plus_one = 1;
	}
	if (my_struct.minus2 > 0 && my_struct.minus > 0)
	{
		if (plus_one == 1)
			ft_putchar('-');
		ft_putstr(*to_print);
		if (my_struct.nb <= ft_strlen2(*to_print))
			my_struct.nb = 0;
		else if (plus_one == 1)
			my_struct.nb = my_struct.nb - (ft_strlen(*to_print) + 1);
		else
			my_struct.nb = my_struct.nb - ft_strlen(*to_print);
		while (++i < my_struct.nb)
			ft_putchar(' ');
		if (plus_one == 1)
			return (my_struct.nb + ft_strlen(*to_print) + 1);
		return (my_struct.nb + ft_strlen(*to_print));
	}
	if (my_struct.minus2 > 0)
	{
		if (my_struct.nb <= ft_strlen2(*to_print))
			my_struct.nb = 0;
		else if (plus_one == 1)
			my_struct.nb = my_struct.nb - (ft_strlen(*to_print) + 1);
		else
			my_struct.nb = my_struct.nb - ft_strlen(*to_print);
		if (plus_one == 1)
			ft_putchar('-');
		while (++i < my_struct.nb)
			ft_putchar('0');
		ft_putstr(*to_print);
		if (plus_one == 1)
			return (my_struct.nb + ft_strlen(*to_print) + 1);
		return (my_struct.nb + ft_strlen(*to_print));
	}
	
	if (my_struct.nb2 <= ft_strlen2(*to_print))
		my_struct.nb2 = 0;
	else
		my_struct.nb2 = my_struct.nb2 -= ft_strlen2(*to_print);
	if (!(str_precision = (char *)malloc(sizeof(char) * (my_struct.nb2 + 1))))
		return (0);
	while (++i < my_struct.nb2)
		str_precision[i] = '0';
	str_precision[i] = 0;
	i = 0;
	if (my_struct.nb <= my_struct.nb2 + ft_strlen2(*to_print))
		my_struct.nb = 0;
	else if (plus_one == 1)
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(*to_print) + 1);
	else
		my_struct.nb = my_struct.nb - (my_struct.nb2 + ft_strlen2(*to_print));
	if (my_struct.minus == 0)
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	if (plus_one == 1)
		ft_putchar('-');
	ft_putstr(str_precision);
	free(str_precision);
	ft_putstr(*to_print);
	if (my_struct.minus == 1)
		while (i++ < my_struct.nb)
			ft_putchar(' ');
	if (plus_one == 1)
		return (my_struct.nb + my_struct.nb2 + ft_strlen(*to_print) + 1);
	return (my_struct.nb + my_struct.nb2 + ft_strlen(*to_print));
	
	/*
	size_t 	nb_precision;
	size_t	nb_space;
	int 	pos_save;
	char	*precision;
	char	*string_space;
	size_t i;

	i = 0;
	nb_precision = 0;
	nb_space = 0;
	pos_save = pos_after_percent;
	if (is_a_minus(*to_print))
		return (print_d_zero_precision_neg(str, pos_after_percent, &to_print, my_struct));
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision <= ft_strlen(*to_print))
		nb_precision = 0;
	else
		nb_precision = nb_precision - ft_strlen(*to_print);
	if (!(precision = (char *)malloc(sizeof(char) * (nb_precision + 1))))
		return (0);
	while (i < nb_precision)
	{
		precision[i] = '0';
		i++;
	}
	precision[i] = '\0';
	i = 0;
	pos_save++;
	nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
	if (nb_space <= ft_strlen(*to_print) + nb_precision)
		nb_space = 0;
	else
		nb_space = nb_space - (nb_precision + ft_strlen(*to_print));
	if (!(string_space = (char *)malloc(sizeof(char) * (nb_space + 1))))
		return (0);
	while (i < nb_space)
	{
		string_space[i] = ' ';
		i++;
	}
	string_space[i] = '\0';
	ft_putstr(string_space);
	free(string_space);
	ft_putstr(precision);
	free(precision);
	ft_putstr(*to_print);
	return (ft_strlen(*to_print) + nb_space + nb_precision);
	*/
}

	//PRINTF("4.d", 100);
	//PRINTF("*.d", 100);		
int				print_d_nb_and_prec(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (is_fill_with_zero(*to_print))
	{
		while (i++ < my_struct.nb)
			ft_putchar(' ');
		return (my_struct.nb);
	}
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print);
	if (my_struct.minus > 0)
	{
		ft_putstr(*to_print);
		while (i++ < my_struct.nb)
			ft_putchar(' ');
		return (my_struct.nb + ft_strlen2(*to_print));
	}
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(*to_print);
	return (my_struct.nb + ft_strlen2(*to_print));
}
/*
int				print_d_all_in(char **to_print, t_flag my_struct)
{
	printf("%s", *to_print);
	my_struct.len = 0;
	return (0);
}
*/
int				print_d(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*to_print;
	size_t	len;

	len = 0;
	if (str[my_struct.len + pos_after_percent] == 'd' || str[my_struct.len + pos_after_percent] == 'i')
		to_print = ft_itoa(va_arg(args, int));
	else if (str[my_struct.len + pos_after_percent] == 'u')
		to_print = ft_itoa(va_arg(args, unsigned int));
	else if (str[my_struct.len + pos_after_percent] == 'x')
		to_print = ft_itoa_base(va_arg(args, int), 16, 1);
	else if (str[my_struct.len + pos_after_percent] == 'X')
		to_print = ft_itoa_base(va_arg(args, int), 16, 2);

	if (my_struct.len_star > 0)
		my_struct.nb = my_struct.star;
	if (my_struct.len_star2 > 0)
		my_struct.nb2 = my_struct.star2;
	my_struct.len_nb = len_ofnumber(my_struct.nb);
	my_struct.len_nb2 = len_ofnumber(my_struct.nb2);

/*
			printf("\n---------------------------\n");
			printf("\n\n\nstruct.zero : %d\n", my_struct.zero);
			printf("struct.minus : %d\n", my_struct.minus);
			printf("struct.star : %d\n", my_struct.star);
			printf("struct.len_star : %d\n", my_struct.len_star);
			printf("struct.nb : %d\n", my_struct.nb);
			printf("struct.len_nb : %d\n", my_struct.len_nb);
			printf("struct.nb 2: %d\n", my_struct.nb2);
			printf("struct.len_nb2 : %d\n", my_struct.len_nb2);
			printf("struct.precision : %d\n", my_struct.precision);
			printf("struct.minus 2: %d\n", my_struct.minus2);
			printf("struct.star2 : %d\n", my_struct.star2);
			printf("struct.len_star2 : %d\n", my_struct.len_star2);
			printf("struct.len : %d\n", my_struct.len);
			printf("---------------------------\n");
*/

	//PRINTF("%d", 12);				good
	//PRINTF("%-d", 12)				good
	if (my_struct.len == 0 || (my_struct.len == my_struct.minus && my_struct.minus > 0 && my_struct.len_nb == 0))
	{
		ft_putstr(to_print);
		len += ft_strlen(to_print);
	}

	//PRINTF("4.d", 100);			good
	//PRINTF("*.d", 100);			good
	else if (my_struct.minus >= 0 && my_struct.zero == 0 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.nb2 == 0 && my_struct.star2 == -1)
		len += (print_d_nb_and_prec(&to_print, my_struct));

	//PRINTF("%.5d", 12);			good
	//PRINTF("%.*d", 10, 12);		good
	else if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.nb == 0 && my_struct.precision == 1 
			&& my_struct.len_nb2 > 0)
		len += print_d_precision(&to_print, my_struct);


	//PRINTF("%5d", 12);			good
	//PRINTF("%*d", 5, 12);			good
	else if (my_struct.minus == 0 && my_struct.zero == 0 && my_struct.len_nb > 0 && my_struct.precision == 0)
		len += print_d_space(&to_print, my_struct);

	//PRINTF("%-5d", 12);			good
	//PRINTF("%-*d", 5, 12);		good
	else if (my_struct.minus > 0 && my_struct.zero == 0 && my_struct.len_nb > 0 && my_struct.precision == 0)
		len += print_d_minus_space(&to_print, my_struct);

	//PRINTF("%5.2d", 12)			good
	//PRINTF("%*.*d", 5, 3, 12)		good
	else if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
		len += print_d_precision_plus(&to_print, my_struct);
	
	//PRINTF("%-5.2d", 12)			good
	//PRINTF("%-*.*d", 5, 3, 12)	good
	else if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
		len += print_d_precision_minus(&to_print, my_struct);
	
	
	//PRINTF("%015d", 12);			good
	//PRINTF("%0*d", 15, 12);		good
	else if (my_struct.zero == 1 && my_struct.len_nb >= 0 && my_struct.precision == 0)
		len += print_d_zero(&to_print, my_struct);
	
	//PRINTF("%08.5d", 34);			good
	//PRINTF("%0*.5d", 8, 34);		good
	else if (my_struct.minus >= 0 && my_struct.zero == 1 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
		len += print_d_zero_precision(&to_print, my_struct);
/*
	//"[%00*.83x]", -100,3683218368u
	else if (my_struct.zero == 1 && my_struct.minus > 0 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
		len += print_d_all_in(&to_print, my_struct);
*/

	//PRINTF("%.d", 100)	
	else if (my_struct.len == 1 && my_struct.precision == 1)
	{
		if (is_fill_with_zero(to_print))
			return (0);
		ft_putstr(to_print);
		return (ft_strlen(to_print));
	}
	
	free(to_print);
	return (len);
}
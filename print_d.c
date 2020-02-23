/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:27:59 by tembu             #+#    #+#             */
/*   Updated: 2020/02/23 22:18:47 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//PRINTF("%5d", 12);
int				print_d_space(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t 	nb_space;
	size_t 	i;

	nb_space = 0;
	i = 0;
	nb_space = small_atoi_final(str, &pos_after_percent, nb_space, my_struct);
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
	return (ft_strlen(*to_print) + nb_space);
}

//PRINTF("%-5d", 12);
int				print_d_minus_space(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t 	nb_space;
	size_t 	i;

	nb_space = 0;
	i = 0;
	pos_after_percent++;
	ft_putstr(*to_print);
	nb_space = small_atoi_final(str, &pos_after_percent, nb_space, my_struct);
//	printf("\nnb space : %zu\n", nb_space);
//	printf("\nto print : %s\n", *to_print);
	if (nb_space <= ft_strlen(*to_print))
		return (ft_strlen(*to_print));
	nb_space = nb_space - ft_strlen(*to_print);
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	return (ft_strlen(*to_print) + nb_space);
}


//PRINTF("%015", 12);
int				print_d_zero(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t 		nb_zero;
	size_t 		i;
	int 		neg;
	
	nb_zero = 0;
	i = 0;
	neg = 0;
	pos_after_percent++;
	nb_zero = small_atoi_final(str, &pos_after_percent, nb_zero, my_struct);
	if (nb_zero <= ft_strlen(*to_print))
		nb_zero = 0;
	else
		nb_zero = nb_zero - ft_strlen(*to_print);
	if (is_a_minus(*to_print))
	{
		*to_print = min_2_plus(&*to_print);
		neg = 1;
	}
	while (i++ < nb_zero)
		ft_putchar('0');
	ft_putstr(*to_print);
	if (neg == 1)
		return (ft_strlen(*to_print) + nb_zero + 1);
	return (ft_strlen(*to_print) + nb_zero);
}

//PRINTF("%.5d", 12);
int				print_d_precision(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t 	nb_precision;
	size_t 	i;
	char	*precision;
	int neg;

	nb_precision = 0;
	i = 0;
	neg = 0;
	if (is_a_minus(*to_print))
	{
		*to_print = min_2_plus(&*to_print);
		neg = 1;
	}
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (is_fill_with_zero(*to_print) && nb_precision == 0)
		return (0);
	if (nb_precision <= ft_strlen(*to_print))
		nb_precision = 0;
	else
		nb_precision = nb_precision - ft_strlen(*to_print);
	if (!(precision = (char *)malloc(sizeof(char) * (nb_precision + 1))))
		return (0);
	while (i++ < nb_precision)
			ft_putchar('0');
	free(precision);
	ft_putstr(*to_print);
	if (neg == 1 && nb_precision > ft_strlen(*to_print))
		return (ft_strlen(*to_print) + nb_precision + 1);

	else if (neg == 1 && nb_precision <= ft_strlen(*to_print))
		return (ft_strlen(*to_print) + 1);
	else
		return (ft_strlen(*to_print) + nb_precision);
}

int				print_d_precision_minus_neg(const char *str, int pos_after_percent, char ***to_print, t_flag my_struct)
{
	size_t 	nb_precision;
	size_t	nb_space;
	int 	pos_save;
	char	*string_space;
	size_t i;
	long long result;

	i = 0;
	result = 0;
	nb_precision = 0;
	nb_space = 0;
	pos_save = pos_after_percent;
	**to_print = min_2_plus(&**to_print);
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision <= ft_strlen(**to_print))
		nb_precision = 0;
	else
		nb_precision = nb_precision - ft_strlen(**to_print);
	while (i++ < nb_precision)
		ft_putchar('0');
	i = 0;
	pos_save++;
	nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
	if (nb_space <= (ft_strlen(**to_print) + nb_precision))
		nb_space = 0;
	else
		nb_space = nb_space - (ft_strlen(**to_print) + nb_precision + 1);
	if (!(string_space = (char *)malloc(sizeof(char) * (nb_space + 1))))
		return (0);
	while (i < nb_space)
	{
		string_space[i] = ' ';
		i++;
	}
	string_space[i] = '\0';
	ft_putstr(**to_print);
	ft_putstr(string_space);
	free(string_space);
	return (nb_precision + nb_space + ft_strlen(**to_print) + 1);
}

int				print_d_precision_minus(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
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
		return (print_d_precision_minus_neg(str, pos_after_percent, &to_print, my_struct));
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (is_fill_with_zero(*to_print) && nb_precision == 0)
	{
		pos_save++;
		nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
		while (i < nb_space)
		{
			ft_putchar(' ');
			i++;
		}
		return (nb_space);
	}
	if (nb_precision < ft_strlen(*to_print))
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
	ft_putstr(precision);
	free(precision);
	ft_putstr(*to_print);
	i = 0;
	pos_save++;
	nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
	if (nb_space < ft_strlen(*to_print) + nb_precision)
		nb_space = 0;
	else
		nb_space = nb_space - (ft_strlen(*to_print) + nb_precision);
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
	return (ft_strlen(*to_print) + nb_space + nb_precision);
	
}
int				print_d_precision_plus_neg(const char *str, int pos_after_percent, char ***to_print, t_flag my_struct)
{
	size_t 	nb_precision;
	size_t	nb_space;
	int 	pos_save;
	char	*precision;
	long long result;
	size_t i;

	i = 0;
	nb_precision = 0;
	nb_space = 0;
	result = 0;
	pos_save = pos_after_percent;
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision <= ft_strlen(**to_print) - 1)
	{
		nb_precision = 0;
		precision = ft_strdup("");
	}
	else
	{
		nb_precision = nb_precision - (ft_strlen(**to_print) - 1);
		if (!(precision = (char *)malloc(sizeof(char) * (nb_precision + 1))))
			return (0);
		while (i < nb_precision)
		{
			precision[i] = '0';
			i++;
		}
		precision[i] = '\0';
	}
	i = 0;
	nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
	if (nb_space <= (ft_strlen(precision) + ft_strlen(**to_print)))
		nb_space = 0;
	else
		nb_space = nb_space - (ft_strlen(precision) + ft_strlen(**to_print));
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	result = ft_atoi(**to_print) * (-1);
	free(**to_print);
	**to_print = ft_itoa(result);
	ft_putchar('-');
	if (is_fill_with_zero(precision))
		ft_putstr(precision);
	ft_putstr(**to_print);
	return (nb_space + ft_strlen(**to_print) + nb_precision + 1);
}

int				print_d_precision_plus(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t 	nb_precision;
	size_t	nb_space;
	int 	pos_save;
	char	*precision;
	size_t i;

	i = 0;
	nb_precision = 0;
	nb_space = 0;
	pos_save = pos_after_percent;
	if (is_a_minus(*to_print))
		return (print_d_precision_plus_neg(str, pos_after_percent, &to_print, my_struct));
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (is_fill_with_zero(*to_print) && nb_precision == 0)
	{
		nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
		while (i < nb_space)
		{
			ft_putchar(' ');
			i++;
		}
		return (nb_space);
	}
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
	nb_space = small_atoi_final(str, &pos_save, nb_space, my_struct);
	if (nb_space <= ft_strlen(*to_print) + nb_precision)
		nb_space = 0;
	else
		nb_space = nb_space - (nb_precision + ft_strlen(*to_print));
	while (i < nb_space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(precision);
	free(precision);
	ft_putstr(*to_print);
	return (ft_strlen(*to_print) + nb_space + nb_precision);
}

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

int				print_d_zero_precision_neg(const char *str, int pos_after_percent, char ***to_print, t_flag my_struct)
{
	size_t 	nb_precision;
	size_t	nb_space;
	int 	pos_save;
	char	*precision;
	char	*string_space;
	size_t i;
	long long result;

	i = 0;
	result = 0;
	nb_precision = 0;
	nb_space = 0;
	pos_save = pos_after_percent;

	result = ft_atoi(**to_print) * (-1);
	free(**to_print);
	**to_print = ft_itoa(result);

	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision <= ft_strlen(**to_print))
		nb_precision = 0;
	else
		nb_precision = nb_precision - ft_strlen(**to_print);
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
	if (nb_space <= ft_strlen(**to_print) + nb_precision)
		nb_space = 0;
	else
		nb_space = nb_space - (ft_strlen(**to_print) + nb_precision + 1);
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
	ft_putchar('-');
	ft_putstr(precision);
	free(precision);
	ft_putstr(**to_print);
	return (ft_strlen(**to_print) + nb_precision + nb_space + 1);
}

int				print_d_zero_precision(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
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
}

int				print_d_special_case(const char *str, int pos_after_percent, t_flag my_struct)
{
	size_t nb_space;
	size_t i;

	nb_space = 0;
	i = 0;
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

	//PRINTF("%d", 12);
	if (my_struct.zero == 0 && (my_struct.minus == 0 || my_struct.minus == 1) && my_struct.nb == 0 && my_struct.star == -1 && my_struct.precision == 0)
	{
		ft_putstr(to_print);
		len += ft_strlen(to_print);
	}

	//PRINTF("%5d", 12);
	//PRINTF("%*d", 5, 12);
	else if (my_struct.minus == 0 && my_struct.zero == 0 && (my_struct.nb >= 0 || my_struct.star >= 0) && my_struct.precision == 0)
		len += print_d_space(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("%-5d", 12);
	//PRINTF("%-*d", 5, 12);
	else if (my_struct.minus == 1 && my_struct.zero == 0 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 0)
		len += print_d_minus_space(str, pos_after_percent, &to_print, my_struct);
	
	//PRINTF("%015d", 12);
	//PRINTF("%0*d", 15, 12);
	else if (my_struct.zero == 1 && (my_struct.nb > 0 || my_struct.nb == 0 || my_struct.star >= 0) && my_struct.precision == 0)
		len += print_d_zero(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("%5.2d", 12)
	//PRINTF("%*.*d", 5, 3, 12)
	else if (my_struct.zero == 0 && my_struct.minus == 0 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 1 && (my_struct.nb2 > 0 || my_struct.star2 >= 0))
		len += print_d_precision_plus(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("%.5d", 12);
	//PRINTF("%.*d", 10, 12);
	else if (my_struct.minus == 0 && my_struct.zero == 0 && (my_struct.nb == 0 || my_struct.star == -1) && my_struct.precision == 1 
			&& (my_struct.nb2 > 0 || my_struct.star2 >= 0))
		len += print_d_precision(str, pos_after_percent, &to_print, my_struct);
	
	//PRINTF("%-5.2d", 12)
	//PRINTF("%-*.*d", 5, 3, 12)
	else if (my_struct.zero == 0 && my_struct.minus == 1 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 1 && (my_struct.nb2 > 0 || my_struct.star2 >= 0))
		len += print_d_precision_minus(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("%08.5d", 34);
	//PRINTF("%0*.5d", 8, 34);
	else if (my_struct.minus == 0 && my_struct.zero == 1 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 1 && (my_struct.nb2 > 0 || my_struct.star2 >= 0))
		len += print_d_zero_precision(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("special case");
	else if ((my_struct.minus == 0 && my_struct.zero == 0 && my_struct.nb > 0 && my_struct.precision == 1 && my_struct.nb2 == 0 && is_fill_with_zero(to_print))
			|| (my_struct.minus == 1 && my_struct.zero == 0 && my_struct.nb > 0 && my_struct.precision == 1 && my_struct.nb2 == 0 && is_fill_with_zero(to_print)))
		len += print_d_special_case(str, pos_after_percent, my_struct);
	free(to_print);
	return (len);
}
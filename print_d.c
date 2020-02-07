/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:27:59 by tembu             #+#    #+#             */
/*   Updated: 2020/02/07 18:28:06 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_d_minus_space(const char *str, int pos_after_percent, char **to_print)
{
	size_t 	nb_space;
	size_t 	i;
	char 	*string_space;
	char	to_print_new[ft_strlen(*to_print) + 1];

	nb_space = 0;
	i = 0;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_space <= ft_strlen(*to_print))
		return (ft_strlen(*to_print));
	nb_space = nb_space - ft_strlen(*to_print);
	string_space = (char *)malloc(sizeof(char) * (nb_space + 1));
	while (i < nb_space)
	{
		string_space[i] = ' ';
		i++;
	}
	string_space[i] = '\0';
	ft_strcpy(to_print_new, *to_print);
	*to_print = ft_strjoin(to_print_new, string_space);
	return (ft_strlen(*to_print));
}

int				print_d_space(const char *str, int pos_after_percent, char **to_print)
{
	size_t 	nb_space;
	size_t 	i;
	char 	*string_space;
	char	to_print_new[ft_strlen(*to_print) + 1];

	nb_space = 0;
	i = 0;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_space <= ft_strlen(*to_print))
		return (ft_strlen(*to_print));
	nb_space = nb_space - ft_strlen(*to_print);
	string_space = (char *)malloc(sizeof(char) * (nb_space + 1));
	while (i < nb_space)
	{
		string_space[i] = ' ';
		i++;
	}
	string_space[i] = '\0';
	ft_strcpy(to_print_new, *to_print);
	*to_print = ft_strjoin(string_space, to_print_new);
	return (ft_strlen(*to_print));
}

int				print_d_zero(const char *str, int pos_after_percent, char **to_print)
{
	size_t 	nb_zero;
	size_t 	i;
	char 	*string_zero;
	char	to_print_new[ft_strlen(*to_print) + 1];

	nb_zero = 0;
	i = 0;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_zero = nb_zero * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_zero <= ft_strlen(*to_print))
		return (ft_strlen(*to_print));
	nb_zero = nb_zero - ft_strlen(*to_print);
	string_zero = (char *)malloc(sizeof(char) * (nb_zero + 1));
	while (i < nb_zero)
	{
		string_zero[i] = '0';
		i++;
	}
	string_zero[i] = '\0';
	ft_strcpy(to_print_new, *to_print);	
//	free(*to_print);
	*to_print = ft_strjoin(string_zero, to_print_new);
	return (ft_strlen(*to_print));
}

int				print_d_precision(const char *str, int pos_after_percent, char **to_print)
{
	size_t 	nb_precision;
	size_t 	i;
	char	*precision;
	char	to_print_new[ft_strlen(*to_print) + 1];

	nb_precision = 0;
	i = 0;
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	nb_precision = nb_precision - ft_strlen(*to_print);
	precision = (char *)malloc(sizeof(char) * (nb_precision + 1));
	while (i < nb_precision)
	{
		precision[i] = '0';
		i++;
	}
	precision[i] = '\0';
	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	*to_print = ft_strjoin(precision, to_print_new);
	return (ft_strlen(*to_print));	
}

/*
int				print_d_precision_minus(const char *str, t_flag my_struct, int pos_after_percent, char **to_print)
{
	int 	nb_precision;
	int 	pos_save;
	int 	i;
	char	*precision;
	char	to_print_new[ft_strlen(*to_print) + 1];

	nb_precision = 0;
	i = 0;
	pos_save = pos_after_percent;
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	nb_precision = nb_precision - ft_strlen(*to_print);
	precision = (char *)malloc(sizeof(char) * (nb_precision + 1));
	while (i < nb_precision)
	{
		precision[i] = '0';
		i++;
	}
	precision[i] = '\0';
	ft_strcpy(to_print_new, *to_print);
//	free(*to_print);
	*to_print = ft_strjoin(precision, to_print_new);
	return (print_d_precision_minus2(str, my_struct, pos_save, &to_print));
}

int				print_d_precision_minus2(const char *str, t_flag my_struct, int pos_save, char ***to_print)
{
	int 	nb_precision;
	int 	i;
	char	*precision;
	char	to_print_new[ft_strlen(**to_print) + 1];

	nb_precision = 0;
	i = 0;

	while(str[pos_save] >= '0' && str[pos_save] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_save] - 48;
		pos_save++;
	}
	nb_precision = nb_precision - ft_strlen(**to_print);
	precision = (char *)malloc(sizeof(char) * (nb_precision + 1));
	while (i < nb_precision)
	{
		precision[i] = '0';
		i++;
	}
	precision[i] = '\0';
	ft_strcpy(to_print_new, **to_print);
//	free(**to_print);
	**to_print = ft_strjoin(to_print_new, precision);
	return (ft_strlen(**to_print));
}
*/

int				print_d(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*to_print;
	int 	nb_zero;
	size_t	len;

	nb_zero = 0;
	to_print = ft_strdup(ft_itoa(va_arg(args, int)));
	if (my_struct.minus == 1 && my_struct.zero == 0 && my_struct.nb > 0)
		print_d_minus_space(str, pos_after_percent, &to_print);
	if (my_struct.zero == 0 && my_struct.nb > 0)
		print_d_space(str, pos_after_percent, &to_print);
	if (my_struct.zero == 1)
		print_d_zero(str, pos_after_percent, &to_print);
//	if (my_struct.precision == 1 && my_struct.minus == 1 && my_struct.nb)
//		print_d_precision_minus(str, my_struct, pos_after_percent, &to_print);
	if (my_struct.precision == 1 && my_struct.nb2 > 0)
		print_d_precision(str, pos_after_percent, &to_print);

	ft_putstr(to_print);
	len = ft_strlen(to_print);
	free(to_print);
	return (len);
}
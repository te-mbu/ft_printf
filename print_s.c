/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:16:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/23 21:54:09 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//PRINTF("%5s", "salut")
int				print_s_space(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t i;
	size_t nb_space;

	i = 0;
	nb_space = 0;
	nb_space = small_atoi_final(str, &pos_after_percent, nb_space, my_struct);
	if (nb_space <= ft_strlen(*to_print))
		nb_space = 0;
	else
		nb_space = nb_space - ft_strlen(*to_print);
	while (i++ < nb_space)
		ft_putchar(' ');
	ft_putstr(*to_print);
	return (ft_strlen(*to_print) + nb_space);
}

// PRINTF("%.2s", "salut")
int				print_s_precision(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t i;
	size_t nb_precision;

	i = 0;
	nb_precision = 0;
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision >= ft_strlen(*to_print))
	{
		ft_putstr(*to_print);
		return (ft_strlen(*to_print));
	}
	while (i < nb_precision)
	{
		ft_putchar(to_print[0][i]);
		i++;
	}
	return (nb_precision);
}


//PRINTF("%-10s", "salut");
int				print_s_minus_space(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t i;
	size_t nb_space;
	char *str_space;

	i = 0;
	nb_space = 0;
	pos_after_percent++;
	nb_space = small_atoi_final(str, &pos_after_percent, nb_space, my_struct);
	if (nb_space <= ft_strlen(*to_print))
		nb_space = 0;
	else
		nb_space = nb_space - ft_strlen(*to_print);
	if (!(str_space = (char *)malloc(sizeof(char) * (nb_space + 1))))
		return (0);
	while(i < nb_space)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	ft_putstr(*to_print);
	ft_putstr(str_space);
	free(str_space);
	return (ft_strlen(*to_print) + nb_space);
}

//PRINTF("%10.2s", "salut");
// . . . . . . . . sa
int				print_s_space_precision(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t i;
	size_t nb_precision;
	int pos_save;
	char *str_precision;
	char *str_space;

	i = 0;
	nb_precision = 0;
	pos_save = pos_after_percent;
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision > ft_strlen(*to_print))
		str_precision = ft_strdup(*to_print);
	else
	{
		if (!(str_precision = (char *)malloc(sizeof(char) * (nb_precision + 1))))
			return (0);
		while (i < nb_precision)
		{
			str_precision[i] = to_print[0][i];
			i++;
		}
		str_precision[i] = '\0';
	}
	i = 0;
	nb_precision = 0;
	nb_precision = small_atoi_final(str, &pos_save, nb_precision, my_struct);
	if (nb_precision > ft_strlen(str_precision))
		nb_precision = nb_precision - ft_strlen(str_precision);
	else
		nb_precision = 0;
	if (!(str_space = (char *)malloc(sizeof(char) * (nb_precision + 1))))
		return (0);
	while (i < nb_precision)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	ft_putstr(str_space);
	free(str_space);
	ft_putstr(str_precision);
	return (ft_strlen(str_precision) + nb_precision);
}

//PRINTF("%-10.2s", "salut");
//sa . . . . . . . . 

int				print_s_minus_space_precision(const char *str, int pos_after_percent, char **to_print, t_flag my_struct)
{
	size_t i;
	size_t nb_precision;
	long long result;
	int neg;
	int pos_save;
	char *str_precision;
	char *str_space;

	i = 0;
	nb_precision = 0;
	result = 0;
	neg = 0;
	pos_save = pos_after_percent + 1;
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	nb_precision = small_atoi_final2(str, &pos_after_percent, nb_precision, my_struct);
	if (nb_precision >= ft_strlen(*to_print))
		str_precision = ft_strdup(*to_print);
	else
	{
		if (!(str_precision = (char *)malloc(sizeof(char) * (nb_precision + 1))))
			return (0);
		while (i < nb_precision)
		{
			str_precision[i] = to_print[0][i];
			i++;
		}
		str_precision[i] = '\0';
	}
	i = 0;
	nb_precision = 0;
	if (my_struct.minus == 1 && my_struct.star >= 0)
		pos_save++;
	nb_precision = small_atoi_final(str, &pos_save, nb_precision, my_struct);
	if (nb_precision >= ft_strlen(str_precision))
		nb_precision = nb_precision - ft_strlen(str_precision);
	else
		nb_precision = 0;
	str_space = (char *)malloc(sizeof(char) * (nb_precision + 1));
	if (!str_space)
		return (0);
	while (i < nb_precision)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	ft_putstr(str_precision);
	ft_putstr(str_space);
	free(str_space);
	if (neg == 1)
		return (ft_strlen(str_precision) + nb_precision + 1);
	return (ft_strlen(str_precision) + nb_precision);
}

int				print_s_nb_prec_only(const char *str, int pos_after_percent, t_flag my_struct)
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

int				print_s(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*to_print;
	size_t len;

	len = 0;
	to_print = ft_strdup(va_arg(args, char *));
	if (to_print == NULL)
	{
		free(to_print);
		to_print = ft_strdup("(null)");
	}

	//PRINTF("%s", "hey");
	if (my_struct.len == 0)
	{
		ft_putstr(to_print);
		len += ft_strlen(to_print);
	}

	//PRINTF("%10s", "salut")
	//PRINTF("%*s", 10, "salut")
	else if (my_struct.zero == 0 && my_struct.minus == 0 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 0)
		len += print_s_space(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("%10.2s", "salut");
	// . . . . . . . . sa
	else if (my_struct.zero == 0 && my_struct.minus == 0 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 1 && (my_struct.nb2 > 0 || my_struct.star2 >= 0))
		len += print_s_space_precision(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("-10.2s", "salut")
	else if (my_struct.zero == 0 && my_struct.minus == 1 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 1 && (my_struct.nb2 > 0 || my_struct.star2 >= 0))
		len += print_s_minus_space_precision(str, pos_after_percent, &to_print, my_struct);

	//PRINTF("%3.s", NULL)
	//PRINTF("%*.s", NULL)
	else if ((my_struct.zero == 0 && my_struct.minus == 0 && (my_struct.nb > 0 || my_struct.star >= 0) && (my_struct.nb2 == 0 || my_struct.star2 == -1) && my_struct.precision == 1)
			|| (my_struct.zero == 0 && my_struct.minus == 1 && (my_struct.nb > 0 || my_struct.star >= 0) && (my_struct.nb2 == 0 || my_struct.star2 == -1) && my_struct.precision == 1))
		len += print_s_nb_prec_only(str, pos_after_percent, my_struct);

	// PRINTF("%.2s", "salut")
	// PRINTF("%.*s", 2, "salut")
	else if (my_struct.zero == 0 && my_struct.minus == 0 && (my_struct.nb == 0 || my_struct.star == -1)
			&& (my_struct.nb2 > 0 || my_struct.star2 >= 0) && my_struct.precision == 1)
		len += print_s_precision(str, pos_after_percent, &to_print, my_struct);
	
	//PRINTF("%-10s", "salut");
	//PRINTF("%-*s", 10, "salut");
	else if ( my_struct.zero == 0 && my_struct.minus == 1 && (my_struct.nb > 0 || my_struct.star >= 0) && my_struct.precision == 0)
		len += print_s_minus_space(str, pos_after_percent, &to_print, my_struct);


	free(to_print);
	return (len);
}

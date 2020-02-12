/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:16:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/11 23:09:07 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// PRINTF("%.2s", "salut")
int				print_s_precision(const char *str, int pos_after_percent, char **to_print)
{
	size_t nb_precision;
	char to_print_new[ft_strlen(*to_print) + 1];

	nb_precision = 0;
	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_precision >= ft_strlen(to_print_new))
	{
		*to_print = ft_strdup(to_print_new);
		return (ft_strlen(*to_print));
	}
	*to_print = ft_substr(to_print_new, 0, nb_precision);
	return (ft_strlen(*to_print));
}

//PRINTF("%5s", "salut");
int				print_s_space(const char *str, int pos_after_percent, char **to_print)
{
	size_t i;
	size_t nb_space;
	char *str_space;
	char to_print_new[ft_strlen(*to_print) + 1];

	i = 0;
	nb_space = 0;
	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_space <= ft_strlen(to_print_new))
	{
		*to_print = ft_strdup(to_print_new);
		return (ft_strlen(*to_print));
	}
	nb_space = nb_space - ft_strlen(to_print_new);
	str_space = (char *)malloc(sizeof(char) * (nb_space + 1));
	if (!str_space)
		return (0);
	while(i < nb_space)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	*to_print = ft_strjoin(str_space, to_print_new);
	return (ft_strlen(*to_print));
}

//PRINTF("%-10s", "salut");
int				print_s_minus_space(const char *str, int pos_after_percent, char **to_print)
{
	size_t i;
	size_t nb_space;
	char *str_space;
	char to_print_new[ft_strlen(*to_print) + 1];

	i = 0;
	nb_space = 0;
	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_space <= ft_strlen(to_print_new))
	{
		*to_print = ft_strdup(to_print_new);
		return (ft_strlen(*to_print));
	}
	nb_space = nb_space - ft_strlen(to_print_new);
	str_space = (char *)malloc(sizeof(char) * (nb_space + 1));
	if (!str_space)
		return (0);
	while(i < nb_space)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	*to_print = ft_strjoin(to_print_new, str_space);
	return (ft_strlen(*to_print));
}
//PRINTF("%10.2s", "salut");
// . . . . . . . . sa
int				print_s_space_precision(const char *str, int pos_after_percent, char **to_print)
{
	size_t nb_precision;
	int pos_save;
	char to_print_new[ft_strlen(*to_print) + 1];
	char *str_precision;
	char *str_space;
	size_t i;

	nb_precision = 0;
	i = 0;
	pos_save = pos_after_percent;
	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_precision >= ft_strlen(to_print_new))
		str_precision = ft_strdup(to_print_new);
	else
		str_precision = ft_substr(to_print_new, 0, nb_precision);
	nb_precision = 0;
	while(str[pos_save] >= '0' && str[pos_save] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_save] - 48;
		pos_save++;
	}
	if (nb_precision <= ft_strlen(str_precision))
	{
		*to_print = ft_strdup(str_precision);
		return (ft_strlen(*to_print));
	}
	nb_precision = nb_precision - ft_strlen(str_precision);
	str_space = (char *)malloc(sizeof(char) * (nb_precision + 1));
	if (!str_space)
		return (0);
	while (i < nb_precision)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	*to_print = ft_strjoin(str_space, str_precision);
	return (ft_strlen(*to_print));
}

//PRINTF("%-10.2s", "salut");
//sa . . . . . . . . 

int				print_s_minus_space_precision(const char *str, int pos_after_percent, char **to_print)
{
	size_t nb_precision;
	int pos_save;
	char to_print_new[ft_strlen(*to_print) + 1];
	char *str_precision;
	char *str_space;
	size_t i;

	nb_precision = 0;
	i = 0;
	pos_save = pos_after_percent;
	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	while (str[pos_after_percent] != '.')
		pos_after_percent++;
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_precision >= ft_strlen(to_print_new))
		str_precision = ft_strdup(to_print_new);
	else
		str_precision = ft_substr(to_print_new, 0, nb_precision);
	pos_save++;
	nb_precision = 0;
	while(str[pos_save] >= '0' && str[pos_save] <= '9')
	{
		nb_precision = nb_precision * 10 + str[pos_save] - 48;
		pos_save++;
	}
	if (nb_precision <= ft_strlen(str_precision))
	{
		*to_print = ft_strdup(str_precision);
		return (ft_strlen(*to_print));
	}
	nb_precision = nb_precision - ft_strlen(str_precision);
	str_space = (char *)malloc(sizeof(char) * (nb_precision + 1));
	if (!str_space)
		return (0);
	while (i < nb_precision)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	*to_print = ft_strjoin(str_precision, str_space);
	return (ft_strlen(*to_print));
}

int				print_s_precision_wrong(char **to_print)
{
	char	to_print_new[ft_strlen(*to_print) + 1];

	ft_strcpy(to_print_new, *to_print);
	free(*to_print);
	*to_print = ft_strdup("");
	return (0);
}

int				print_s(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*to_print;
	size_t len;

	len = 0;
	if (!(to_print = ft_strdup(va_arg(args, char*))))
		to_print = ft_strdup("(null)");
	
	if (my_struct.precision == 1 && my_struct.nb2 > 0 && my_struct.nb == 0)
		len += print_s_precision(str, pos_after_percent, &to_print);

	if (my_struct.precision == 1 && my_struct.nb2 == 0 && my_struct.minus == 0)
		len += print_s_precision_wrong(&to_print);

	if (my_struct.nb > 0 && my_struct.minus == 0 && my_struct.precision == 0)
		len += print_s_space(str, pos_after_percent, &to_print);

	if (my_struct.nb > 0 && my_struct.minus == 1 && my_struct.precision == 0)
		len += print_s_minus_space(str, pos_after_percent, &to_print);

	if (my_struct.minus == 1 && my_struct.nb > 0 && my_struct.precision == 1 && my_struct.nb2 > 0)
		len += print_s_minus_space_precision(str, pos_after_percent, &to_print);

	if (my_struct.minus == 0 && my_struct.nb > 0 && my_struct.precision == 1 && my_struct.nb2 > 0)
		len += print_s_space_precision(str, pos_after_percent, &to_print);

	ft_putstr(to_print);
	free(to_print);
	return (len);
}

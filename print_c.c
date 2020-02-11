/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:06:56 by tembu             #+#    #+#             */
/*   Updated: 2020/02/11 20:04:19 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//PRINTF("%c", 'a');
int				print_c_no_flag(char *to_print, char tmp)
{
	to_print[0] = tmp;
	to_print[1] = '\0';
	return (1);
}

//PRINTF("%5c", 'a')

int			print_c_space(const char *str, int pos_after_percent, char **to_print, char tmp)
{
	size_t nb_space;
	char *str_space;
	size_t i;

	nb_space = 0;
	i = 0;
	free(*to_print);
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_space > 1)
		nb_space = nb_space - 1;
	else
		nb_space = 0;
		str_space = (char *)malloc(sizeof(char) * (nb_space + 1));
		if (!str_space)
			return (0);
		while (i < nb_space)
		{
			str_space[i] = ' ';
			i++;
		}
		str_space[i] = '\0';
	
		*to_print = ft_strjoin_char(str_space, tmp);
		return (ft_strlen(*to_print));
}

//PRINTF("%-15c", 'a');
int			print_c_minus_space(const char *str, int pos_after_percent, char **to_print, char tmp)
{
	size_t nb_space;
	char *str_space;
	size_t i;

	nb_space = 0;
	i = 0;
	free(*to_print);
	pos_after_percent++;
	while(str[pos_after_percent] >= '0' && str[pos_after_percent] <= '9')
	{
		nb_space = nb_space * 10 + str[pos_after_percent] - 48;
		pos_after_percent++;
	}
	if (nb_space > 1)
	nb_space = nb_space - 1;
	else
		nb_space = 0;
	str_space = (char *)malloc(sizeof(char) * nb_space + 1);
	if (!str_space)
		return (0);
	while (i < nb_space)
	{
		str_space[i] = ' ';
		i++;
	}
	str_space[i] = '\0';
	*to_print = ft_strjoin_char2(str_space, tmp);
	return (ft_strlen(*to_print));
}

int				print_c(const char *str, t_flag my_struct, va_list args, int pos_after_percent)
{
	char	*to_print;
	char	tmp;
	size_t len;

	to_print = (char*)malloc(sizeof(char) * 2);
	len = 0;
	tmp = va_arg(args, int);

	if (my_struct.nb == 0 && my_struct.minus == 0)
		len += print_c_no_flag(to_print, tmp);
	if (my_struct.nb == 1 && my_struct.minus == 0)
		len += print_c_space(str, pos_after_percent, &to_print, tmp);
	if (my_struct.nb == 1 && my_struct.minus == 1)
		len += print_c_minus_space(str, pos_after_percent, &to_print, tmp);
	ft_putstr(to_print);
	free(to_print);
	return (len);
}
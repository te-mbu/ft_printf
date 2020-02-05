/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:16:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/05 17:34:09 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_s(t_flag my_struct, va_list args)
{
	char	*to_print;
	size_t len;

	to_print = ft_strdup(va_arg(args, char *));
	ft_putstr(to_print);
	len = ft_strlen(to_print);
	free(to_print);
	return (len);
}

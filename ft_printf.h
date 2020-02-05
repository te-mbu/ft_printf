/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:09:13 by tembu             #+#    #+#             */
/*   Updated: 2020/02/05 19:04:32 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_flag {
    int     zero;
    int     minus;
	int		nb;
	int		star;
    int     dot;
    int     len;
}               t_flag;

int			ft_printf(const char *str, ...);

/*
** utils
*/

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
char		*ft_strdup(const char *src);
size_t		ft_strlen(const char *s);
char		*ft_itoa(int n);

/*
** conversions
*/

int			print_s(t_flag my_struct, va_list args);
int			print_d(const char *str, t_flag my_struct, va_list args, int pos_after_percent);
int			ft_conversion(const char *str, t_flag my_struct, va_list args, int *i);
void		ft_init_list(t_flag *my_struct);
void		ft_parsing(const char *str, t_flag *my_struct, int *i);

/*
** flags
*/

void		check_flag_nb_minus_star(const char *str, t_flag *my_struct, int *i);
void		check_flag_zero(const char *str, t_flag *my_struct, int *i);
#endif

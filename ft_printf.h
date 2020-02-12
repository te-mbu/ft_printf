/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:09:13 by tembu             #+#    #+#             */
/*   Updated: 2020/02/12 02:02:28 by tembu            ###   ########.fr       */
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
	int		minus2;
	int		nb;
	int		nb2;
	int		star;
	int		star2;
    int     precision;
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
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_char(const char *s1, const char s2);
char		*ft_strjoin_char2(const char *s1, const char s2);
char		*ft_strcpy(char *dest, char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

/*
** conversions
*/

int			print_s(const char *str, t_flag my_struct, va_list args, int pos_after_percent);
int			print_s_space(const char *str, int pos_after_percent, char **to_print);
int			print_s_minus_space(const char *str, int pos_after_percent, char **to_print);
int			print_s_space_precision(const char *str, int pos_after_percent, char **to_print);
int			print_s_minus_space_precision(const char *str, int pos_after_percent, char **to_print);
int			print_s_precision_wrong(char **to_print);

int			print_d(const char *str, t_flag my_struct, va_list args, int pos_after_percent);
int			print_d_space(const char *str, int pos_after_percent, char **to_print);
int			print_d_minus_space(const char *str, int pos_after_percent, char **to_print);
int			print_d_precision(const char *str, int pos_after_percent, char **to_print);
int			print_d_precision_minus(const char *str, int pos_after_percent, char **to_print);
//int			print_d_precision_minus2(const char *str, t_flag my_struct, int pos_save, char ***to_print);

int			print_c(const char *str, t_flag my_struct, va_list args, int pos_after_percent);
int			print_c_no_flag(char *to_print, char tmp);
int			print_c_space(const char *str, int pos_after_percent, char **to_print, char tmp);

int			print_percent(const char *str, t_flag my_struct, int pos_after_percent);
int			print_percent_no_flag();
int			print_percent_space(const char *str, int pos_after_percent);

int			ft_conversion(const char *str, t_flag my_struct, va_list args, int *i);
void		ft_init_list(t_flag *my_struct);
void		ft_parsing(const char *str, t_flag *my_struct, int *i);

/*
** flags
*/

void		check_flag_nb_minus_star(const char *str, t_flag *my_struct, int *i);
void		check_flag_zero(const char *str, t_flag *my_struct, int *i);
void		check_flag_precision(const char *str, t_flag *my_struct, int *i);
void		check_flag_nb2_minus2_star2(const char *str, t_flag *my_struct, int *i);

#endif

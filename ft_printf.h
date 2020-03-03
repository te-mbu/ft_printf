/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:09:13 by tembu             #+#    #+#             */
/*   Updated: 2020/03/03 22:53:44 by tembu            ###   ########.fr       */
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

typedef struct		s_flag {
	int		zero;
	int		minus;
	int		minus2;
	int		nb;
	int		len_nb;
	int		nb2;
	int		len_nb2;
	int		star;
	int		len_star;
	int		star2;
	int		len_star2;
	int		precision;
	int		len;
}					t_flag;

#define TEST write(1, "test\n", 5);

int					ft_printf(const char *str, ...);

/*
** utils
*/

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *s);
int					ft_strlen2(const char *s);
char				*ft_itoa(long long n);
char				*ft_itoa_base(unsigned int n, unsigned int base,
					int whatsbase);
char				*ft_itoa_base_p(unsigned long n, unsigned long base,
					int whatsbase);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_char(const char *s1, const char s2);
char				*ft_strjoin_char2(const char *s1, const char s2);
char				*ft_strcpy(char *dest, char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					is_a_minus(const char *str);
int					ft_atoi(const char *str);
int					is_fill_with_zero(const char *str);
char				*min_2_plus(char **to_print);
char				*min_2_plus_wo_minus(char **to_print, int *plus_one);
int					len_ofnumber(int nb);
int					print_and_return_size(char **str);
int					ft_len_to_print(char **to_print);
int					ft_freeint(char *str, int ret);
int					ft_putstr_and_free(char *str, int i);

/*
** conversions
*/

int					print_s(t_flag my_struct, va_list args);
int					print_s_nb_prec_only(t_flag my_struct);
int					print_s_precision(char **to_print, t_flag my_struct);
int					print_s_space(char *to_print, t_flag my_struct);
int					print_s_minus_space(char *to_print, t_flag my_struct);
int					print_s_space_precision(char **to_print, t_flag my_struct);
int					print_s_minus_space_precision(char **to_print,
					t_flag my_struct);
int					print_s_space_precision_sc1(char **to_print,
					t_flag my_struct);
int					print_s_minus_space_precision_sc1(t_flag my_struct,
					char **to_print);
int					print_d(const char *str, t_flag my_struct, va_list args,
					int pos_after_percent);
int					print_d_space(char *to_print, t_flag my_struct);
int					print_d_minus_space(char *to_print, t_flag my_struct);
int					print_d_precision_plus(char *to_print, t_flag my_struct,
					int i, int plus_one);
int					print_d_precision_minus(char *to_print, t_flag my_struct);
int					print_d_zero(char *to_print, t_flag my_struct);
int					print_d_precision(char *to_print, t_flag my_struct,
					int i, int plus_one);
int					print_d_nb_and_prec(char *to_print, t_flag my_struct);
int					print_d_zero_precision(char *to_print, t_flag my_struct,
					int i, int plus_one);
int					print_d_precision_minus_sc1(t_flag my_struct,
					char *to_print, int plus_one);
int					print_d_precision_plus2(t_flag my_struct, int plus_one,
					char *to_print, char *str_precision);
int					print_d_zero_precision_sc1(t_flag my_struct,
					char *to_print, int plus_one);
int					print_percent_no_flag(void);
int					print_percent_zero(t_flag my_struct);
int					print_percent_minus_zero(t_flag my_struct);
int					print_percent_space(t_flag my_struct);
int					print_percent_minus_space(t_flag my_struct);
int					print_percent(t_flag my_struct);
int					print_c_no_flag(char tmp);
int					print_c_space(char tmp, t_flag my_struct);
int					print_c_minus_space(char tmp, t_flag my_struct);
int					print_c(t_flag my_struct, va_list args);
int					print_x(const char *str, t_flag my_struct, va_list args,
					int pos_after_percent);
int					print_p(t_flag my_struct, va_list args);
int					print_p_space(char *to_print, t_flag my_struct);
int					print_p_minus_space(char *to_print, t_flag my_struct);
int					ft_input_equal_zero(const char *str, int pos_after_percent,
					t_flag my_struct);
int					ft_conversion(const char *str, t_flag my_struct,
					va_list args, int *i);
void				ft_init_list(t_flag *my_struct);
void				ft_parsing(const char *str, t_flag *my_struct,
					va_list args, int *i);
int					ft_zero_case(t_flag my_struct, char *to_print, int i);
int					ft_zero_case6(t_flag my_struct, int i);
int					ft_zero_case5_sc1(t_flag my_struct, int i);

/*
** flags
*/

void				check_flag_nb_minus_star(const char *str, t_flag *my_struct,
					va_list args, int *i);
void				check_flag_zero(const char *str, t_flag *my_struct, int *i);
void				check_flag_precision(const char *str,
					t_flag *my_struct, int *i);
void				check_flag_nb2_minus2_star2(const char *str,
					t_flag *my_struct, va_list args, int *i);

#endif

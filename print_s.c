/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:16:02 by tembu             #+#    #+#             */
/*   Updated: 2020/02/26 05:35:00 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//PRINTF("%5s", "salut")			good
int				print_s_space(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(*to_print);
	return (my_struct.nb + ft_strlen(*to_print));
}

//PRINTF("%-10s", "salut");			good
//PRINTF("%-*s", 10, "salut");		good
int				print_s_minus_space(char **to_print, t_flag my_struct)
{
	int i;

	i = 0;
	if (my_struct.nb <= ft_strlen2(*to_print))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen2(*to_print);
	ft_putstr(*to_print);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	return (my_struct.nb + ft_strlen(*to_print));
}

//PRINTF("%10.2s", "salut");		good
// . . . . . . . . sa				
int				print_s_space_precision(char **to_print, t_flag my_struct)
{
	int 	i;
	char	*str_precision;

	i = -1;
	if (my_struct.minus2 > 0)
	{
		if (my_struct.nb <= ft_strlen2(*to_print))
			my_struct.nb = 0;
		else
			my_struct.nb = my_struct.nb -= ft_strlen(*to_print);
		while (++i < my_struct.nb)
			ft_putchar(' ');
		ft_putstr(*to_print);
		return (my_struct.nb + ft_strlen2(*to_print));
	}
	if (my_struct.nb2 >= ft_strlen2(*to_print))
	{
		my_struct.nb2 = ft_strlen2(*to_print);
		str_precision = ft_strdup(*to_print);
	}
	else
	{
		if (!(str_precision = (char *)malloc(sizeof(char) * (my_struct.nb2) + 1)))
			return (0);
		while (++i < my_struct.nb2)
			str_precision[i] = to_print[0][i];
		str_precision[i] = 0;
	}
	i = 0;
	if (my_struct.nb <= ft_strlen2(str_precision))
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= ft_strlen(str_precision);
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	ft_putstr(str_precision);
	free(str_precision);
	return(my_struct.nb + my_struct.nb2);
}


//PRINTF("%-10.2s", "salut");		good
//sa . . . . . . . . 

int				print_s_minus_space_precision(char **to_print, t_flag my_struct)
{
	int 	i;
//TO DO - A CHANGER 
	i = -1;

	if (my_struct.minus > 0 && my_struct.minus2 > 0)
	{
		ft_putstr(*to_print);
		if (my_struct.nb <= ft_strlen2(*to_print))
			my_struct.nb = 0;
		else
			my_struct.nb = my_struct.nb - ft_strlen(*to_print);
		while (++i < my_struct.nb)
			ft_putchar(' ');
		return (my_struct.nb + ft_strlen(*to_print));
	}

	if (my_struct.minus2 > 0)					// A CHANGER PEUT ETRE
	{
		ft_putstr(*to_print);
		return (ft_strlen(*to_print));
	}
	if (my_struct.nb2 >= ft_strlen2(*to_print))
	{
		my_struct.nb2 = ft_strlen(*to_print);
		ft_putstr(*to_print);
	}
	else
		while (++i < my_struct.nb2)
			ft_putchar(to_print[0][i]);
	i = 0;
	if (my_struct.nb <= my_struct.nb2)
		my_struct.nb = 0;
	else
		my_struct.nb = my_struct.nb -= my_struct.nb2;
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	return(my_struct.nb + my_struct.nb2);
}

// PRINTF("%.2s", "salut")			good
int				print_s_precision(char **to_print, t_flag my_struct)
{
	int i;
//	write(1, "\n\ntest\n\n", 8);
	i = 0;
	if (my_struct.minus2 > 0)
	{
		ft_putstr(*to_print);
		return (ft_strlen(*to_print));
	}
	if (my_struct.nb2 >= ft_strlen2(*to_print))
	{
		my_struct.nb2 = ft_strlen2(*to_print);
		ft_putstr(*to_print);
		return (ft_strlen2(*to_print));
	}
	else
		while (i < my_struct.nb2)
		{
			ft_putchar(to_print[0][i]);
			i++;
		}	
	return (my_struct.nb2);
}

//PRINTF("%3.s", NULL)				good
//PRINTF("%*.s", NULL)				good
int				print_s_nb_prec_only(t_flag my_struct)
{
	int i;

	i = 0;
	while (i++ < my_struct.nb)
		ft_putchar(' ');
	return (my_struct.nb);
}

int				print_s(t_flag my_struct, va_list args)
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
	//PRINTF("%s", "hey");				good
	//PRINTF(%-s)						good
	if (my_struct.len == 0 ||
			(my_struct.len == my_struct.minus && my_struct.zero == 0 && my_struct.minus > 0 &&
					my_struct.len_nb == 0 && my_struct.precision == 0 && my_struct.len_nb2 == 0))
	{
		ft_putstr(to_print);
		len += ft_strlen(to_print);
	}

	//PRINTF("%3.s", NULL)				good
	//PRINTF("%*.s", NULL)				good
	else if ((my_struct.zero == 0 && (my_struct.minus == 0 || my_struct.minus > 0) && my_struct.nb > 0
		&& my_struct.precision == 1 && my_struct.star2 == -1 && my_struct.nb2 == 0))
		len += print_s_nb_prec_only(my_struct);

	
	//PRINTF("%10s", "salut")			good
	//PRINTF("%*s", 10, "salut")		good
	else if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.len_nb > 0 && my_struct.precision == 0)
		len += print_s_space(&to_print, my_struct);

	//PRINTF("%-10s", "salut");			good
	//PRINTF("%-*s", 10, "salut");		good
	else if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb > 0 && my_struct.precision == 0)
		len += print_s_minus_space(&to_print, my_struct);

	// PRINTF("%.3s", "salut")			good
	// PRINTF("%.*s", 3, "salut")		good
	else if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.nb == 0 && my_struct.len_nb2 > 0 && my_struct.precision == 1)
		len += print_s_precision(&to_print, my_struct);
		
	//PRINTF("%10.2s", "salut");		good
	// . . . . . . . . sa
	else if (my_struct.zero == 0 && my_struct.minus == 0 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
		len += print_s_space_precision(&to_print, my_struct);




	//PRINTF("-10.2s", "salut");		good
	else if (my_struct.zero == 0 && my_struct.minus > 0 && my_struct.len_nb > 0 && my_struct.precision == 1 && my_struct.len_nb2 > 0)
		len += print_s_minus_space_precision(&to_print, my_struct);

	free(to_print);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/07 18:24:43 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{

	printf("*****MY PRINTF*****\n");
	printf("ret : %d\n\n", ft_printf("->%-10d<-\n", 12));
	printf("*****REAL PRINTF*****\n");
	printf("ret : %d\n\n", printf("->%-10d<-\n", 12));

//	printf("%-10.5d", 12);
}
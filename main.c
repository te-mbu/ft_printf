/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/05 18:41:27 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{

	printf("*****MY PRINTF*****\n");
	printf("ret : %d\n\n", ft_printf("bonjour %58074-*s a toi\n", "hey"));
//	printf("*****REAL PRINTF*****\n");
//	printf("ret : %d\n", printf("bonjour %s a toi\n", "hey"));

//	printf("%04d03", 12);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/23 22:19:42 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{

#define INPUT "[%4.d]", -100


		write(1, "\n***FT_PRINTF***\n\n", 17);
		printf(" ret : %d\n", ft_printf(INPUT));
		write(1, "\n***REAL PRINTF***\n", 19);
		printf(" ret : %d\n", printf(INPUT));

//	printf("%s", "salut");
}
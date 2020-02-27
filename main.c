/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/27 17:13:43 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
int a = (void*)0;
//#define INPUT "[%00*.83x]", -18,3683218368u
#define INPUT "[%.p]", &a

		write(1, "\n***FT_PRINTF***\n\n", 17);
		printf(" ret : %d\n", ft_printf(INPUT));
		write(1, "\n***REAL PRINTF***\n", 19);
		printf(" ret : %d\n", printf(INPUT));

//	printf("%s", "salut");
}
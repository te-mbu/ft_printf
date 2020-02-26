/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/26 05:35:40 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
int a = 10;
//#define INPUT "[%00*.83x]", -18,3683218368u
#define INPUT "[%-*.*s]", 151, -6,"KKbR)R0\tL%7<1,kb>w.4"

		write(1, "\n***FT_PRINTF***\n\n", 17);
		printf(" ret : %d\n", ft_printf(INPUT));
		write(1, "\n***REAL PRINTF***\n", 19);
		printf(" ret : %d\n", printf(INPUT));

//	printf("%s", "salut");
}
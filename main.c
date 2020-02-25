/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/25 20:35:26 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{

//#define INPUT "%*.3s", -15, "ABC"
//#define INPUT "%-*.3s", 15, "ABC" //good
#define INPUT "[%---*d]", -19, -1

//#define INPUT "[%10.2s]", "ABC"     //good

		write(1, "\n***FT_PRINTF***\n\n", 17);
		printf(" ret : %d\n", ft_printf(INPUT));
		write(1, "\n***REAL PRINTF***\n", 19);
		printf(" ret : %d\n", printf(INPUT));

//	printf("%s", "salut");
}
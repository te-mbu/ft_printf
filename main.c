/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:47:34 by tembu             #+#    #+#             */
/*   Updated: 2020/02/12 04:56:52 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
#  define INPUT "%10.s", "salut"
		printf("\nret :%d\n", ft_printf(INPUT));
		printf("\nret :%d\n", printf(INPUT));

//printf("%.-5%");
}

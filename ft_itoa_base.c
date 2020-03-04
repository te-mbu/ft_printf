/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:54:45 by tembu             #+#    #+#             */
/*   Updated: 2020/03/04 11:46:43 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		ft_intlen(unsigned int n, unsigned int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char					*ft_itoa_base(unsigned int n,
					unsigned int base, int whatsbase)
{
	unsigned int	len;
	char			*s;
	char			*rep;

	if (whatsbase == 1)
		rep = "0123456789abcdef";
	else
		rep = "0123456789ABCDEF";
	len = ft_intlen(n, base);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		s[len - 1] = 0 + '0';
	s[len] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = rep[n % base];
		n /= base;
	}
	return (s);
}

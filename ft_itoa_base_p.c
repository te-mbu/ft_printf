/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:46:33 by tembu             #+#    #+#             */
/*   Updated: 2020/02/26 00:01:54 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned long n, unsigned long base)
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

char		*ft_itoa_base_p(unsigned long n, unsigned long base, int whatsbase)
{
	unsigned long	len;
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
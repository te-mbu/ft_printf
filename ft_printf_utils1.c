/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:08:59 by tembu             #+#    #+#             */
/*   Updated: 2020/02/10 14:23:54 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void			ft_putnbr(int n)
{
	int div;
	int mod;

	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putstr("2147483648");
			return ;
		}
		n *= -1;
	}
	div = n / 10;
	mod = n % 10;
	if (div)
		ft_putnbr(div);
	ft_putchar(mod + 48);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*string;
	int		size;

	i = 0;
	size = ft_strlen(src);
	string = NULL;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	while (src[i])
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

size_t			ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (i < s1[i])
	{
		string[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < s2[i])
		string[j++] = s2[i++];
	string[len] = '\0';
	return (string);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

void		ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return ;
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	result = NULL;
	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}

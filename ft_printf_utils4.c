/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:57:52 by tembu             #+#    #+#             */
/*   Updated: 2020/02/29 18:04:02 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_strlen2(const char *s)
{
	int i;

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

char				*ft_strcpy(char *dest, char *src)
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

int					print_and_return_size(char **str)
{
	ft_putstr(*str);
	free(*str);
	return (ft_strlen(*str));
}

char				*min_2_plus_wo_minus(char **to_print, int *plus_one)
{
	long long result;

	result = ft_atoi(*to_print) * (-1);
	free(*to_print);
	*to_print = ft_itoa(result);
	*plus_one = 1;
	return (*to_print);
}

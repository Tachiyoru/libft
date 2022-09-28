/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:37:37 by sleon             #+#    #+#             */
/*   Updated: 2022/05/21 16:22:32 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	int	size;

	size = 1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_char(int n)
{
	char	c;

	c = n % 10 + '0';
	return (c);
}

char	*ft_negative(int n)
{
	int		i;
	char	*dest;

	n *= -1;
	i = ft_size(n) + 1;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	while (--i > 0)
	{
		dest[i] = ft_char(n);
		n = n / 10;
	}
	dest[i] = '-';
	return (dest);
}

char	*ft_int_min(int n)
{
	int		i;
	char	*dest;

	n *= -1;
	i = 11;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	dest[i - 1] = '8';
	dest[i - 2] = '4';
	dest[i - 3] = '6';
	dest[i - 4] = '3';
	dest[i - 5] = '8';
	dest[i - 6] = '4';
	dest[i - 7] = '7';
	dest[i - 8] = '4';
	dest[i - 9] = '1';
	dest[i - 10] = '2';
	dest[i - 11] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dest;

	if (n == -2147483648)
		return (ft_int_min(n));
	if (n < 0)
		return (ft_negative(n));
	i = ft_size(n);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	while (--i >= 0)
	{
		dest[i] = ft_char(n);
		n = n / 10;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:52:57 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/05 13:20:49 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static void	reverse(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_itoa_base(unsigned long value, int base, int dig, int j)
{
	char			*str;
	int				i;
	int				is_negative;
	unsigned long	n;
	char			digits[17];

	while (dig < 16)
	{
		if (dig <= 9)
			digits[dig] = '0' + dig;
		else
		{
			digits[dig] = 'a' + j;
			j++;
		}
		dig++;
	}
	digits[16] = '\0';
	i = 0;
	is_negative = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (value < 0 && base == 10)
	{
		is_negative = 1;
		n = -value;
	}
	else
		n = (unsigned long)value;
	str = malloc(70);
	if (!str)
		return (NULL);
	while (n > 0)
	{
		str[i++] = digits[n % base];
		n /= base;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

static int	count_digits(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(int n)
{
	char *str;
	long nb;
	int len;
	int i;

	nb = n;
	if (n < 0)
	{
		nb = 4294967296 + nb;
	}

	len = count_digits(nb);
	i = len - 1;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';

	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}

	return (str);
}
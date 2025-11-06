/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:52:57 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/06 13:36:06 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	count_digits(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static unsigned long	ft_handle_sign(int value, int base, int *sign)
{
	unsigned long	num;

	*sign = 0;
	if (value < 0 && base == 10)
	{
		*sign = 1;
		num = -(unsigned long)value;
	}
	else
	{
		num = (unsigned long)value;
	}
	return (num);
}

char	*ft_itoa_base(int value, int base)
{
	char			*str;
	char			*digits;
	unsigned long	num;
	int				sign;
	int				len;

	digits = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	num = ft_handle_sign(value, base, &sign);
	len = count_digits(num, base) + sign;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = digits[num % base];
		num /= base;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_utoa(int n)
{
	char	*str;
	long	nb;
	int		len;
	int		i;

	nb = n;
	if (n < 0)
	{
		nb = 4294967296 + nb;
	}
	len = count_digits(nb, 10);
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

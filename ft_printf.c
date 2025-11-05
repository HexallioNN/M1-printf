/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:47:32 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/05 14:15:20 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd' || *fmt == 'i')
				count = ft_dicase(va_arg(args, int), count);
			else if (*fmt == 'c')
				count = ft_ccase(va_arg(args, int), count);
			else if (*fmt == 's')
				count = ft_scase(va_arg(args, char *), count);
			else if (*fmt == 'p')
				count = ft_pcase(va_arg(args, void *), count);
			else if (*fmt == 'u')
				count = ft_ucase(va_arg(args, unsigned int), count);
			else if (*fmt == 'x' || *fmt == 'X')
				count = ft_xcase(va_arg(args, int), count, *fmt);
			else if (*fmt != '\0')
				count = ft_emptycase(count, *fmt);
			fmt++;
		}
		else
		{
			count = ft_emptycase(count, *fmt);
			fmt++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	tse;
	int	*ptr;

	tse = 1;
	ptr = &tse;
	ft_printf("another test %%\n");
	printf("another test %%\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:47:32 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/01 15:05:35 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

// CODE A FUNCTION THAT WILL CALL EVERY TEST FUNCTION FOR
//% CASES AND CODE THE OTHER TEST CASE FUNCTIONS FOR NOW WE ONLY HAVE %D
int	ft_printf(const char *fmt, ...)
{
	char	tempc;
	va_list	args;
	char	*temp;
	int		count;

	count = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd')
			{
				temp = ft_itoa(va_arg(args, int));
				count += write(1, temp, ft_strlen(temp));
				free(temp);
				fmt++;
			}
			else if (*fmt == 'c')
			{
				tempc = va_arg(args, int);
				count += write(1, &tempc, 1);
				fmt++;
			}
			else if (*fmt == 's')
			{
				count += write(1, va_arg(args, char *), ft_strlen(va_arg(args,
								char *)));
				fmt++;
			}
			// else if (*fmt == 'p')
			// {
			// }
			else if (*fmt != '\0')
			{
				count += write(1, fmt, 1);
				fmt++;
			}
		}
		else
		{
			count += write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("another test %c %d", 'c', 123);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:47:32 by ikalach           #+#    #+#             */
/*   Updated: 2025/10/31 15:14:00 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

// CODE ALL TESTS FUNCTION THAT WILL CALL EVERY TEST FUNCTION FOR
//% CASES AND CODE THE OTHER TEST CASE FUNCTIONS FOR NOW WE ONLY HAVE %D
int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*temp;

	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd')
			{
				temp = ft_itoa(va_arg(args, int));
				write(1, temp, ft_strlen(temp));
				free(temp);
			}
			fmt++;
		}
		write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (1);
}

// int	main(void)
// {
// 	ft_printf("This is a %d test123", 12352163);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:47:32 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/01 16:13:23 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

// CODE A FUNCTION THAT WILL CALL EVERY TEST FUNCTION FOR
//% CASES AND CODE THE OTHER TEST CASE FUNCTIONS FOR NOW WE ONLY HAVE %d %c %%
//	%s (kinda)
int	ft_printf(const char *fmt, ...)
{
	char			tempc;
	va_list			args;
	char			*temps;
	int				count;
	unsigned long	tempp;

	count = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd')
			{
				temps = ft_itoa(va_arg(args, int));
				count += write(1, temps, ft_strlen(temps));
				free(temps);
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
				temps = va_arg(args, char *);
				count += write(1, temps, ft_strlen(temps));
				fmt++;
			}
			else if (*fmt == 'p')
			{
				tempp = (unsigned long)va_arg(args, void *);
				count += write(1, "0x", 2);
				temps = ft_itoa_base(tempp, 16, 0, 0);
				if (temps)
				{
					count += write(1, temps, ft_strlen(temps));
					free(temps);
				}
				fmt++;
			}
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
// 	int	tse;
// 	int	*ptr;

// 	ptr = &tse;
// 	ft_printf("another test %c %d %s %d %c %p %%\n", 'b', 123, "test", 123, 'a',
// 		ptr);
// 	printf("another test %c %d %s %d %c %p %%\n", 'b', 123, "test", 123, 'a',
// 		ptr);
// }

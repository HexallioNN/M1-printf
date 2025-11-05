/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:47:32 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/05 12:48:16 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *fmt, ...)
{
	char			tempc;
	va_list			args;
	char			*temps;
	int				count;
	unsigned long	tempp;
	unsigned int	tempi;

	count = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd' || *fmt == 'i')
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
			else if (*fmt == 'u')
			{
				tempi = (unsigned int)va_arg(args, unsigned int);
				temps = ft_itoa(tempi);
				count += write(1, temps, ft_strlen(temps));
				free(temps);
				fmt++;
			}
			else if (*fmt == 'x' || *fmt == 'X')
			{
				temps = ft_itoa_base(va_arg(args, int), 16, 0, 0);
				if (temps)
				{
					if (*fmt == 'X')
					{
						tempi = 0;
						while (temps[tempi] != '\0')
						{
							temps[tempi] = ft_toupper(temps[tempi]);
							tempi++;
						}
					}
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

// 	tse = 1;
// 	ptr = &tse;
// 	ft_printf("another test %X\n", 123123123);
// 	printf("another test %X\n", 123123123);
// }

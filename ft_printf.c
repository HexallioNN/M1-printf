/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:47:32 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/06 13:35:57 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			count = handle_format_case(*fmt, &args, count);
			if (*fmt)
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

// int	main(void)
// {
// 	int	tse;
// 	int	*ptr;

// 	tse = 1;
// 	ptr = &tse;
// 	ft_printf("another test %c %s %d %i %u %x %%\n", 'a', "test", 1, 2, -3, 4);
// 	printf("another test %c %s %d %i %u %x %%\n", 'a', "test", 1, 2, -3, 4);
// }

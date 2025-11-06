/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:38:19 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/06 10:44:20 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	handle_format_case(char spec, va_list *args, int count)
{
	if (spec == 'd' || spec == 'i')
		count = ft_dicase(va_arg(*args, int), count);
	else if (spec == 'c')
		count = ft_ccase(va_arg(*args, int), count);
	else if (spec == 's')
		count = ft_scase(va_arg(*args, char *), count);
	else if (spec == 'p')
		count = ft_pcase(va_arg(*args, void *), count);
	else if (spec == 'u')
		count = ft_ucase(va_arg(*args, unsigned int), count);
	else if (spec == 'x' || spec == 'X')
		count = ft_xcase(va_arg(*args, unsigned int), count, spec);
	else if (spec == '%')
		count = ft_emptycase(count, '%');
	else if (spec != '\0')
		count = ft_emptycase(count, spec);
	return (count);
}

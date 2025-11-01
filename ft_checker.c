/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:38:19 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/01 13:43:51 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include "libftprintf.h"

// int	ft_checker(char *fmt, va_list(args))
// {
// 	if (*fmt == '%')
// 	{
// 		fmt++;
// 		if (*fmt == 'd')
// 		{
// 			temp = ft_itoa(va_arg(args, int));
// 			count += write(1, temp, ft_strlen(temp));
// 			free(temp);
// 			fmt++;
// 		}
// 		else if (*fmt != '\0')
// 		{
// 			count += write(1, fmt, 1);
// 			fmt++;
// 		}
// 	}
// }
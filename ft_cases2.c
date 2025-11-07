/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:02:25 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/07 14:12:50 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// int	ft_xcase(unsigned int variable, int count, char string)
// {
// 	int		uppercase;
// 	char	*temps;
// 	int		temp;

// 	temp = 0;
// 	uppercase = 0;
// 	if (string == 'X')
// 		uppercase = 1;
// 	else
// 		uppercase = 0;
// 	temps = ft_itoa_base_unsigned(variable, 16);
// 	if (uppercase == 1)
// 	{
// 		while (temps)
// 		{
// 			ft_toupper(temps[temp]);
// 			temp++;
// 		}
// 	}
// 	if (temps)
// 	{
// 		count += write(1, temps, ft_strlen(temps));
// 		free(temps);
// 	}
// 	return (count);
// }

int	ft_xcase(unsigned int variable, int count, char string)
{
	char	*temps;
	int		tempi;

	temps = ft_itoa_base_unsigned(variable, 16);
	if (temps)
	{
		if (string == 'X')
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
	return (count);
}

int	ft_emptycase(int count, char string)
{
	count += write(1, &string, 1);
	return (count);
}

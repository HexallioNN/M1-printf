/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:02:25 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/05 14:08:04 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_xcase(int variable, int count, char string)
{
	char	*temps;
	int		tempi;

	temps = ft_itoa_base(variable, 16, 0, 0);
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

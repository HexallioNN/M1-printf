/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:44:25 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/07 16:52:56 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_dicase(int variable, int count)
{
	char	*temps;

	temps = ft_itoa(variable);
	count += write(1, temps, ft_strlen(temps));
	free(temps);
	return (count);
}

int	ft_ccase(int variable, int count)
{
	int	tempc;

	tempc = variable;
	count += write(1, &tempc, 1);
	return (count);
}

int	ft_scase(char *variable, int count)
{
	char	*temps;

	if (variable)
		temps = variable;
	else
		temps = "(null)";
	count += write(1, temps, ft_strlen(temps));
	return (count);
}

int	ft_pcase(void *variable, int count)
{
	unsigned long	tempp;
	char			*temps;

	if (variable == 0)
	{
		count += write(1, PTRNULL, ft_strlen(PTRNULL));
		return (count);
	}
	tempp = (unsigned long)(variable);
	count += write(1, "0x", 2);
	temps = ft_itoa_base_unsigned(tempp, 16);
	if (temps)
	{
		count += write(1, temps, ft_strlen(temps));
		free(temps);
	}
	return (count);
}

int	ft_ucase(unsigned int variable, int count)
{
	int		tempi;
	char	*temps;

	tempi = (unsigned int)variable;
	temps = ft_utoa(tempi);
	count += write(1, temps, ft_strlen(temps));
	free(temps);
	return (count);
}

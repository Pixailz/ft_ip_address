/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:34:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 09:41:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief				Try to convert a nstr to integer
 *
 * @param nstr			string to convert
 * @param has_flow	variable to for over|under flow
 *
 * @return (int)		set has_flow to 1 if overflow, 2 if underflow
 * 						otherwise return number
 * @note				if error occur, return value is not reliable
 */
static int	ft_atoi_protected(const char *nstr, int *has_flow)
{
	char	*nptr;
	int		to_dec;
	int		neg;

	to_dec = 0;
	neg = 1;
	nptr = (char *)nstr;
	*has_flow = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
		if (*nptr++ == '-')
			neg = ~(neg - 1);
	while (*nptr >= '0' && *nptr <= '9' && !*has_flow)
	{
		to_dec = (to_dec * 0xA) + (*nptr++ & 0xF);
		*has_flow = ft_isgoodi(to_dec, neg);
	}
	return (to_dec * neg);
}

int	ft_patoi(const char *nstr, int *has_flow)
{
	int	to_dec;

	to_dec = 0;
	if (has_flow == FT_NULL)
		to_dec = ft_atoi(nstr);
	else
		to_dec = ft_atoi_protected(nstr, has_flow);
	return (to_dec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base_padded.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:25:32 by stales            #+#    #+#             */
/*   Updated: 2022/11/06 12:18:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

t_size	ft_nbrlen_base_padded(const void *void_nbr, const char *base)
{
	t_size	size;
	t_size	size_base;
	t_int64	nb;

	size = 0;
	if ((t_int64)void_nbr == 0)
		return (1);
	size_base = ft_strlen((char *)base);
	nb = (t_int64)void_nbr;
	if (nb < 0)
	{
		nb = ~(nb - 1);
		size++;
	}
	while (nb && ++size)
		nb /= size_base;
	return (size);
}

/**
 * @brief			Constructs a string representation of an integer, given a
 *					base.
 *
 * @param const_nb	Integer to convert
 * @param base		String base to convert from
 *
 * @return (char *)	The converted value or FT_NULL on error
 */
char	*ft_utoa_base_padded(const t_uint64 const_nb, const char *base)
{
	t_uint64	nb;
	t_size		nb_size;
	t_size		nb_length;
	t_size		padding;
	char		*nb_str;

	nb = (t_uint64)const_nb;
	nb_size = ft_nbrlen_base_padded((void *)const_nb, base);
	nb_length = ((nb_size / 8) + (nb_size % 8 != 0)) * 8;
	nb_str = ft_calloc(1, nb_length + 1);
	if (!nb_str)
		return (FT_NULL);
	padding = nb_length - nb_size;
	ft_memset(nb_str, '0', padding);
	if (nb == 0)
		nb_str[padding] = base[0];
	while (nb)
	{
		nb_str[--nb_size + padding] = base[nb % ft_strlen((char *)base)];
		nb /= ft_strlen((char *)base);
	}
	return (nb_str);
}

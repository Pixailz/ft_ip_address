/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisalnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:39:55 by pix               #+#    #+#             */
/*   Updated: 2022/10/14 05:17:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_check.h"

t_bool	ft_sisalnum(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
		if (!ft_isalnum(*ptr++))
			return (FALSE);
	return (TRUE);
}

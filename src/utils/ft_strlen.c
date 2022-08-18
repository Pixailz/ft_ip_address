/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:57:16 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 04:58:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	ft_strlen(const char *str)
{
	char	*str_ptr;

	str_ptr = (char *)str;
	while (*str_ptr)
		str_ptr++;
	return (str_ptr - str);
}

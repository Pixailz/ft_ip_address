/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 05:06:58 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 19:00:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	parse_is_valid_ip_part(const char *ip_str)
{
	ft_is
}

int	parse_is_valid_ip(const char *ip_str)
{
	char	ip_part[4];
	char	*ip_str_ptr;

	ip_str_ptr = (char *)ip_str;
	ft_strncpy(ip_part, (char *)ip_str, 4);

	return (0);
}

int	parse_entry(const char *ip_str)
{
	if (!*ip_str)
		return (1);
	if (parse_is_valid_ip(ip_str))
		return (2);
	return (0);
}

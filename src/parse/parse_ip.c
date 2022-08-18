/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 05:06:58 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 20:48:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	parse_is_valid_ip_part(const char *ip_str)
{
	if (!ft_isdigit(ip_str[0]))
		return (1);
	if (!ft_isdigit(ip_str[1]))
		return (1);
	if (!ft_isdigit(ip_str[2]))
		return (1);
	if (ip_str[3] != '.')
		return (1);
	return (0);
}

int	parse_is_valid_ip(const char *ip_str)
{
	char	ip_part[4];
	char	*ip_str_ptr;
	int		return_code;
	int		counter;

	ip_str_ptr = (char *)ip_str;
	counter = 0;
	while (counter++ < 3)
	{
		ft_strncpy(ip_part, ip_str_ptr, 4);
		ip_str_ptr += 4;
		return_code = parse_is_valid_ip_part(ip_part);
		if (return_code)
			return (1);
	}
	ft_strncpy(ip_part, ip_str_ptr, 3);
	if (!ft_isdigit(ip_part[0]))
		return (1);
	if (!ft_isdigit(ip_part[1]))
		return (1);
	if (!ft_isdigit(ip_part[2]))
		return (1);
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

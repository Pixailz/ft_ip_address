/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:39:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 15:02:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

int	parse_get_ip(t_int4 *ip_int, char *argv_1)
{
	t_int4	tmp;

	if (ft_strncmp("0.0.0.0\0", argv_1, 8) == 0)
	{
		*ip_int = 0;
		return (0);
	}
	tmp = ft_ipstr(argv_1);
	if (tmp == 0)
		return (2);
	*ip_int = tmp;
	return (0);
}

int	parse_get_netmask(t_ip *ip_struct, char *netmask_str)
{
	int		has_overflow;
	int		n;

	n = ft_patoi(netmask_str, &has_overflow);
	if (has_overflow)
		return (3);
	if (n < 1 || n > 32)
		return (4);
	ip_struct->netmask_n = n;
	ip_struct->netmask_int = 0;
	while (n)
		ip_struct->netmask_int = ip_struct->netmask_int + (1U << (31 - --n));
	return (0);
}

int	parse_split_arg(t_ip *ip_struct, char *argv_1)
{
	char	**arg_splited;
	int		return_value;

	arg_splited = ft_split(argv_1, '/');
	if (arg_splited[1] == FT_NULL)
	{
		ft_free_char_pp(arg_splited);
		return (1);
	}
	return_value = parse_get_ip(&ip_struct->ip_int, arg_splited[0]);
	if (return_value != 0)
	{
		ft_free_char_pp(arg_splited);
		return (return_value);
	}
	return_value = parse_get_netmask(ip_struct, arg_splited[1]);
	ft_free_char_pp(arg_splited);
	if (return_value != 0)
		return (return_value);
	return (return_value);
}

void	parse_entry(t_ip *ip_struct, char *argv_1)
{
	int	return_value;

	return_value = parse_split_arg(ip_struct, argv_1);
	if (return_value != 0)
		parse_error(return_value);
}

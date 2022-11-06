/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:03:30 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 15:42:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

char	init_get_ip_class(t_int4 top_part)
{
	if (top_part <= CLASS_A_MAX)
		return ('A');
	if (top_part >= CLASS_B_MIN && top_part <= CLASS_B_MAX)
		return ('B');
	if (top_part >= CLASS_C_MIN && top_part <= CLASS_C_MAX)
		return ('C');
	if (top_part >= CLASS_D_MIN && top_part <= CLASS_D_MAX)
		return ('D');
	if (top_part >= CLASS_E_MIN && top_part <= CLASS_E_MAX)
		return ('E');
	return ('S');
}

void	init_entry(t_ip *ip_struct, char *argv_1)
{
	ft_memset(ip_struct, 0, sizeof(t_ip));
	parse_entry(ip_struct, argv_1);
	ip_struct->ip_class = \
		init_get_ip_class(ft_int4_dcomp(ip_struct->ip_int, 3));
	ip_struct->wildcard_int = ~ip_struct->netmask_int;
	ip_struct->network_int = ip_struct->ip_int & ip_struct->netmask_int;
	ip_struct->broadcast_int = ip_struct->ip_int | ip_struct->wildcard_int;
	ip_struct->network_int_max = ip_struct->broadcast_int;
	ft_int4_dec(&ip_struct->network_int_max, 0);
	ip_struct->network_int_min = ip_struct->network_int;
	ft_int4_inc(&ip_struct->network_int_min, 0);
	ip_struct->broadcast_int = ip_struct->ip_int | ip_struct->wildcard_int;
	ip_struct->broadcast_int = ip_struct->ip_int | ip_struct->wildcard_int;
	debug_entry(1, (void *)ip_struct);
}

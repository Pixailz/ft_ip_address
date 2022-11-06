/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:07:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 15:09:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

void	debug_init(const t_ip *ip)
{
	ft_printf("ip->ip_int       : [%u]\n", ip->ip_int);
	ft_printf("ip->netmask_int  : [%u]\n", ip->netmask_int);
	ft_printf("ip->wildcard_int : [%u]\n", ip->wildcard_int);
	ft_printf("ip->network_int : [%u]\n", ip->network_int);
	ft_printf("ip->broadcast_int : [%u]\n", ip->broadcast_int);
}

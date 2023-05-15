/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ip_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:53:23 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 16:22:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

void	print_info(t_ip *ip)
{
	ft_printf("Address");
	print_ip_padded(ip->ip_int, 0, ip->netmask_n);
	ft_printf("Netmask");
	print_ip_padded(ip->netmask_int, 0, ip->netmask_n);
	ft_printf("Wildcard");
	print_ip_padded(ip->wildcard_int, 0, ip->netmask_n);
	ft_printf("==>\n");
	ft_printf("Network [CLASS %c]", ip->ip_class);
	print_ip_padded(ip->network_int, ip->netmask_n, ip->netmask_n);
	ft_printf("HostMin");
	print_ip_padded(ip->network_int_min, 0, ip->netmask_n);
	ft_printf("HostMax");
	print_ip_padded(ip->network_int_max, 0, ip->netmask_n);
	ft_printf("Broadcast");
	print_ip_padded(ip->broadcast_int, 0, ip->netmask_n);
	ft_printf("hosts number");
	ft_printf("\x1b[%dG", FIRST_COL);
	ft_printf("[%d]\n", ip->wildcard_int - 1);
}

int	main(int argc, char **argv)
{
	t_ip	ip;

	if (argc != 2)
		return (ft_error("args", 1));
	init_entry(&ip, argv[1]);
	print_info(&ip);
	return (0);
}

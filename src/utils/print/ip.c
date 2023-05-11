/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:12:56 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 16:44:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

void	print_ip(t_int4 ip_int, int subnet)
{
	t_int1	part_1;
	t_int1	part_2;
	t_int1	part_3;
	t_int1	part_4;

	part_1 = ft_int4_dcomp(ip_int, 0);
	part_2 = ft_int4_dcomp(ip_int, 1);
	part_3 = ft_int4_dcomp(ip_int, 2);
	part_4 = ft_int4_dcomp(ip_int, 3);
	if (subnet != 0)
		ft_printf("[%s%u%s.%s%u%s.%s%u%s.%s%u%s/%s%d%s]   ", \
			COLOR_IP_1, part_4, C_RESET, COLOR_IP_1, part_3, C_RESET, \
			COLOR_IP_1, part_2, C_RESET, COLOR_IP_1, part_1, C_RESET, \
			COLOR_IP_2, subnet, C_RESET);
	else
		ft_printf("[%s%u%s.%s%u%s.%s%u%s.%s%u%s]   ", \
			COLOR_IP_1, part_4, C_RESET, COLOR_IP_1, part_3, C_RESET, \
			COLOR_IP_1, part_2, C_RESET, COLOR_IP_1, part_1, C_RESET);
}

void	print_ip_padded(t_int4 ip_int, int subnet, int sub_n)
{
	ft_printf("\x1b[%dG", FIRST_COL);
	print_ip(ip_int, subnet);
	ft_printf("\x1b[%dG", SEC_COL);
	print_binary_ip(ip_int, sub_n - 1);
}

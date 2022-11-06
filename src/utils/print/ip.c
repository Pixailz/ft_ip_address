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
			G_RED, part_4, C_RESET, G_RED, part_3, C_RESET, \
			G_RED, part_2, C_RESET, G_RED, part_1, C_RESET, \
			G_GREEN, subnet, C_RESET);
	else
		ft_printf("[%s%u%s.%s%u%s.%s%u%s.%s%u%s]   ", \
			G_RED, part_4, C_RESET, G_RED, part_3, C_RESET, \
			G_RED, part_2, C_RESET, G_RED, part_1, C_RESET);
}

t_size	print_ip_get_len(t_int4 ip_int, int subnet)
{
	t_int64		part_1;
	t_int64		part_2;
	t_int64		part_3;
	t_int64		part_4;
	t_size		len;

	part_1 = ft_int4_dcomp(ip_int, 0);
	part_2 = ft_int4_dcomp(ip_int, 1);
	part_3 = ft_int4_dcomp(ip_int, 2);
	part_4 = ft_int4_dcomp(ip_int, 3);
	len = 7 + ft_nbrlen((void *)part_1);
	len += ft_nbrlen((void *)part_2);
	len += ft_nbrlen((void *)part_3);
	len += ft_nbrlen((void *)part_4);
	if (subnet == 0)
		return (len);
	else if (subnet < 10)
		return (len + 2);
	else
		return (len + 3);
}

void	print_ip_padded(t_int4 ip_int, t_size writed, int subnet, int sub_n)
{
	int		space_n;
	int		counter;

	writed += print_ip_get_len(ip_int, subnet);
	space_n = PADDING_BINARY - writed;
	counter = 0;
	while (counter < space_n)
	{
		ft_putchar_fd(' ', 1);
		counter++;
	}
	print_ip(ip_int, subnet);
	print_binary_ip(ip_int, sub_n - 1);
}

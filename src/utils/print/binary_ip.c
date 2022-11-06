/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_ip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:38:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 16:44:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

void	print_binary_ip_part_2(t_size *printed, t_size sub_n, char tmp_char)
{
	if (tmp_char == '0')
	{
		if (*printed == sub_n)
			ft_printf("%s%c%s ", G_RED, tmp_char, C_RESET);
		else
			ft_printf("%s%c%s", G_RED, tmp_char, C_RESET);
	}
	else
	{
		if (*printed == sub_n)
			ft_printf("%s%c%s ", G_GREEN, tmp_char, C_RESET);
		else
			ft_printf("%s%c%s", G_GREEN, tmp_char, C_RESET);
	}
	(*printed)++;
}

void	print_binary_ip_part(t_int1 part, t_size sub_n, t_bool is_last)
{
	static t_size	printed = 0;
	int				counter;
	char			*to_str;

	to_str = ft_utoa_base_padded(part, "01");
	counter = 0;
	while (counter < 8)
		print_binary_ip_part_2(&printed, sub_n, to_str[counter++]);
	if (is_last)
		printed = 0;
	free(to_str);
}

void	print_binary_ip(t_int4 n, int sub_n)
{
	print_binary_ip_part(ft_int4_dcomp(n, 3), sub_n, FALSE);
	ft_printf(".");
	print_binary_ip_part(ft_int4_dcomp(n, 2), sub_n, FALSE);
	ft_printf(".");
	print_binary_ip_part(ft_int4_dcomp(n, 1), sub_n, FALSE);
	ft_printf(".");
	print_binary_ip_part(ft_int4_dcomp(n, 0), sub_n, TRUE);
	ft_printf("\n");
}

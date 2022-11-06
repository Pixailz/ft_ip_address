/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:58:42 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 09:56:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

void	parse_error(int return_value)
{
	if (return_value == 1)
		ft_error("not a good ip.", 0);
	else if (return_value == 2)
		ft_error("not a good ip.", 0);
	else if (return_value == 3)
		ft_error("netmask int overflow", 0);
	else if (return_value == 4)
		ft_error("illegal netmask", 0);
	exit(return_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:54:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 05:02:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	ft_error(char *msg, int return_code)
{
	if (msg)
	{
		ft_putstr_fd(2, "ERROR ");
		ft_putstr_fd(2, msg);
		ft_putchar_fd(2, '\n');
	}
	else
		ft_putstr_fd(2, "ERROR\n");
	return (return_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:54:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 12:36:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	ft_error(char *msg, int return_code)
{
	if (msg)
		ft_printf_fd(2, "ERROR %s\n", msg);
	else
		ft_printf_fd(2, "ERROR\n");
	return (return_code);
}

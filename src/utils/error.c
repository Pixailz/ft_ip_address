/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:54:14 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 18:49:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	error_parse(int return_code)
{
	if (return_code == 1)
		ft_error("ip should not be empty", 0);
	return (return_code);
}

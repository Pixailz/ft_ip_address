/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ip_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:53:23 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 20:47:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ip_address.h"

int	main(int argc, char **argv)
{
	int	return_code;

	if (argc != 2)
		return (ft_error("args", 1));
	return_code = parse_entry(argv[1]);
	if (return_code)
		return (error_parse(return_code));
	return (0);
}

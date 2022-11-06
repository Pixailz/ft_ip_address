/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:07:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 13:19:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ip_address.h>

void	debug_entry(int mode, void *args)
{
	if (DEBUG != 1)
		return ;
	if (mode == 1)
		debug_init((t_ip *)args);
}

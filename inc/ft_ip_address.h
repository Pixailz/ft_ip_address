/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ip_address.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:52:55 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 20:40:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IP_ADDRESS_H
# define FT_IP_ADDRESS_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <unistd.h>
# include "libft_print.h"
# include "libft_string.h"
# include "libft_check.h"

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_ip_address.c
int		main(int argc, char **argv);

// parse/parse_ip.c
int		parse_entry(const char *ip_str);
int		parse_is_valid_ip(const char *ip_str);

// utils/error.c
int		error_parse(int return_code);

/* ########################################################################## */

#endif

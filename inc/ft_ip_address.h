/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ip_address.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:52:55 by brda-sil          #+#    #+#             */
/*   Updated: 2022/11/06 16:45:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IP_ADDRESS_H
# define FT_IP_ADDRESS_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <unistd.h>
# include <libft.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

// print debug info
# ifndef DEBUG
#  define DEBUG					0
# endif

// pad for ip in binary
# define PADDING_BINARY			40

# define C_RED					"\001\033[31m\002"
# define C_GREEN				"\001\033[32m\002"
# define C_LIGHT_GREEN			"\001\033[38;5;112m\002"
# define C_YELLOW				"\001\033[33m\002"
# define C_ORANGE				"\001\033[38;5;208m\002"
# define C_BLUE					"\001\033[34m\002"
# define C_PURPLE				"\001\033[35m\002"
# define C_MAGENTA				"\001\033[36m\002"
# define C_WHITE				"\001\033[37m\002"
# define C_BLACK				"\001\033[30m\002"

# define B_RED					"\001\033[01;31m\002"
# define B_GREEN				"\001\033[01;32m\002"
# define B_LIGHT_GREEN			"\001\033[01;38;5;112m\002"
# define B_YELLOW				"\001\033[01;33m\002"
# define B_ORANGE				"\001\033[01;38;5;208m\002"
# define B_BLUE					"\001\033[01;34m\002"
# define B_PURPLE				"\001\033[01;35m\002"
# define B_MAGENTA				"\001\033[01;36m\002"
# define B_WHITE				"\001\033[01;37m\002"
# define B_BLACK				"\001\033[01;30m\002"

# define C_RESET				"\001\033[0m\002"

# define G_RED					B_RED
# define G_GREEN				B_GREEN

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

# define CLASS_A_MIN			0b00000000
# define CLASS_A_MAX			0b01111110
# define CLASS_B_MIN			0b10000000
# define CLASS_B_MAX			0b10111111
# define CLASS_C_MIN			0b11000000
# define CLASS_C_MAX			0b11011111
# define CLASS_D_MIN			0b11100000
# define CLASS_D_MAX			0b11101111
# define CLASS_E_MIN			0b11110000
# define CLASS_E_MAX			0b11111111

typedef struct s_ip
{
	char		ip_class;
	t_int4		ip_int;
	t_int4		netmask_int;
	t_int4		wildcard_int;
	t_int4		network_int;
	t_int4		network_int_min;
	t_int4		network_int_max;
	t_int4		broadcast_int;
	int			netmask_n;
}				t_ip;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// debug/debug_entry.c
void	debug_entry(int mode, void *args);

// debug/init.c
void	debug_init(const t_ip *ip);

// ft_ip_address.c
void	print_info(t_ip *ip);

// init/entry.c
char	init_get_ip_class(t_int4 top_part);
void	init_entry(t_ip *ip_struct, char *argv_1);

// parsing/entry.c
int		parse_get_ip(t_int4 *ip_int, char *argv_1);
int		parse_get_netmask(t_ip *ip_struct, char *netmask_str);
int		parse_split_arg(t_ip *ip_struct, char *argv_1);
void	parse_entry(t_ip *ip_struct, char *argv_1);

// parsing/error.c
void	parse_error(int return_value);

// utils/ft_utoa_base_padded.c
char	*ft_utoa_base_padded(const t_uint64 const_nb, const char *base);
t_size	ft_nbrlen_base_padded(const void *void_nbr, const char *base);

// utils/print/binary_ip.c
void	print_binary_ip(t_int4 n, int sub_n);
void	print_binary_ip_part(t_int1 part, t_size sub_n, t_bool is_last);
void	print_binary_ip_part_2(t_size *printed, t_size sub_n, char tmp_char);

// utils/print/ip.c
t_size	print_ip_get_len(t_int4 ip_int, int subnet);
void	print_ip(t_int4 ip_int, int subnet);
void	print_ip_padded(t_int4 ip_int, t_size writed, int subnet, int sub_n);

/* ########################################################################## */

#endif

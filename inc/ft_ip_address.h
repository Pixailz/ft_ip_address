/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ip_address.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 04:52:55 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/18 05:04:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IP_ADDRESS_H
# define FT_IP_ADDRESS_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include <unistd.h>

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_ip_address.c
int		main(int argc, char **argv);

// utils/ft_error.c
int		ft_error(char *msg, int return_code);

// utils/ft_putchar_fd.c
void	ft_putchar_fd(int fd, const char c);

// utils/ft_putstr_fd.c
void	ft_putstr_fd(int fd, const char *str);

// utils/ft_strlen.c
int		ft_strlen(const char *str);

/* ########################################################################## */

#endif

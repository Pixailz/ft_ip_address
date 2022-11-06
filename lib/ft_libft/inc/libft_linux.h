/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_linux.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/15 11:56:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LINUX_H
# define LIBFT_LINUX_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* TYPEDEF */
/* ####### */

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# ifndef LIBFT_RANDOM
// ft_tmpfile.c
char	*ft_tmpfile(int in_tmp);
# endif

# ifndef LIBFT_CHECK
// ft_isdir.c
int		ft_isdir(char *dir_name, int mode);
# endif

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_getgid.c
int		ft_getgid(void);
int		ft_getgid_dir(char *file_path);
int		ft_getgid_file(char *file_path);

// ft_getuid.c
int		ft_getuid(void);
int		ft_getuid_dir(char *file_path);
int		ft_getuid_file(char *file_path);

// ft_iscdable.c
t_bool	ft_iscdable(char *dir_path);

// ft_isexec.c
t_bool	ft_isexec(char *file_path);

// ft_isdir.c
int		ft_isdir(char *dir_path, int mode);

// ft_isfile.c
int		ft_isfile(char *file_path, int mode);

/* ########################################################################## */

#endif

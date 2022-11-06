/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:16:35 by brda-sil          #+#    #+#             */
/*   Updated: 2022/10/17 09:48:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# ifndef LIBFT_DEFINE_H
#  include "libft_define.h"
# endif

# include <stdlib.h>

/* ########################################################################## */

/* ########################################################################## */
/* REQUIREMENTS */
/* ############ */

# ifndef LIBFT_INTEGER
// ft_nbrlen_base.c
t_size		ft_nbrlen_base(const void *void_nbr, const char *base);

// ft_int4_chg.c
void		ft_int4_chg(t_int4 *n, int level, t_int1 change);

// ft_int4_comp.c
t_int4		ft_int4_comp(t_int1 n1, t_int1 n2, t_int1 n3, t_int1 n4);

// ft_nbrlen.c
t_size		ft_nbrlen(const void *void_nbr);

// ft_get_base.c
int			ft_get_base(int c, const char *base);
# endif

# ifndef LIBFT_CHECK
// ft_isgoodi.c
int			ft_isgoodi(int n, int neg);

// ft_isgoodll.c
int			ft_isgoodll(t_int64 n, int neg);

// ft_isgoodu.c
t_bool		ft_isgoodu(t_uint32 n, int is_last);

// ft_sisdigit.c
t_bool		ft_sisdigit(const char *str);

# endif

# ifndef LIBFT_MEMORY
// ft_calloc.c
void		*ft_calloc(t_size nmemb, t_size size);

// ft_free_char_pp.c
void		ft_free_char_pp(char **str_str);

// ft_memset.c
void		*ft_memset(void *s, int c, t_size n);
# endif

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_atoi.c
int			ft_atoi(const char *nstr);

// ft_atoi_base.c
int			ft_atoi_base(const char *nstr, const char *base);

// ft_atoll.c
t_int64		ft_atoll(const char *nstr);

// ft_atoll_base.c
t_int64		ft_atoll_base(const char *nstr, const char *base);

// ft_atou.c
t_uint64	ft_atou(const char *nstr);

// ft_atou_base.c
t_uint64	ft_atou_base(const char *nstr, const char *base);

// ft_get_words.c
int			ft_get_words(char *str, char c);

// ft_ipstr.c
t_int4		ft_ipstr(char *str);
char		**ft_ip_check(char *str);
int			ft_ip_check_part(char *splitted);

// ft_patoi.c
int			ft_patoi(const char *nstr, int *has_overflow);

// ft_patoi_base.c
int			ft_patoi_base(			\
				const char *nstr,	\
				const char *base,	\
				int *has_overflow	\
			);

// ft_patoll.c
t_int64		ft_patoll(const char *nstr, int *has_overflow);

// ft_patoll_base.c
t_int64		ft_patoll_base(			\
				const char *nstr,	\
				const char *base,	\
				int *has_overflow	\
			);

// ft_patou.c
t_uint32	ft_patou(const char *nstr, int *has_overflow);

// ft_patou_base.c
t_uint32	ft_patou_base(			\
				const char *nstr,	\
				const char *base,	\
				int *has_overflow	\
			);

// ft_split.c
char		**ft_split(char *s, char c);

// ft_splitb.c
int			ft_splitb_get_word(char **str, char delim, char *encl);
int			ft_splitb_get_size(char *str, char delim, char *encl);
char		**ft_splitb_get_words(char *s, char delim, char *encl, \
				int tab_size);
char		**ft_splitb(char *s, char delim, char *encl);

// ft_strcat.c
char		*ft_strcat(char *dest, char *src);

// ft_strcchr.c
int			ft_strcchr(char *str, char c);

// ft_strchr.c
char		*ft_strchr(const char *s, int c);

// ft_strclr.c
void		ft_strclr(char *s);

// ft_strcmp.c
int			ft_strcmp(char *s1, char *s2);

// ft_strcpy.c
char		*ft_strcpy(char *dest, char *src);

// ft_strcspn.c
t_size		ft_strcspn(char *s, const char *rejects);

// ft_strdel.c
void		ft_strdel(char **as);

// ft_strdup.c
char		*ft_strdup(char *src);

// ft_striteri.c
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

// ft_strjoin.c
char		*ft_strjoin(char const *s1, char const *s2);

// ft_strlcat.c
t_uint32	ft_strlcat(char *dest, char *src, t_size size);

// ft_strlcpy.c
t_uint32	ft_strlcpy(char *dest, char *src, t_size size);

// ft_strlen.c
int			ft_strlen(char *str);

// ft_strmapi.c
char		*ft_strmapi(char const *s1, char (*f)(unsigned int, char));

// ft_strncat.c
char		*ft_strncat(char *dest, char *src, t_size n);

// ft_strncmp.c
int			ft_strncmp(char *s1, char *s2, t_size n);

// ft_strncpy.c
char		*ft_strncpy(char *dest, char *src, t_size n);

// ft_strnstr.c
char		*ft_strnstr(char *str, char *to_find, int n);

// ft_strrchr.c
char		*ft_strrchr(const char *s, int c);

// ft_strspn.c
size_t		ft_strspn(char *s, const char *accepts);

// ft_strtok.c
char		*ft_strtok(char *str, char *token);

// ft_strtrim.c
char		*ft_strtrim(char const *s1, char const *set);

// ft_substr.c
char		*ft_substr(char const *s, unsigned int start, t_size len);

// ft_tolower.c
int			ft_tolower(int c);

// ft_toupper.c
int			ft_toupper(int c);

/* ########################################################################## */

#endif

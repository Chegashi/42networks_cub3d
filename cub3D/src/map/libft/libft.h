/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:21:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/19 16:57:00 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT__LIBFT_H
# define __FT__LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_putstr(char *str);
int			ft_isdigit(int c);
int			get_next_line(int fd, char **line);
int			get_buffer(int fd, char **line);
void		ft_end(char **line, char **tmp, int end);
char		*ft_char_calloc(size_t cont);
char		*ft_strdup(const char *src);
int			ft_the_end(char **tmp, char **line, char **end);
char		*ft_strjoinn(char *s1, char const *s2);
int			ft_isin(char *s, char c);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi_s(char **s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *s, size_t len);
#endif

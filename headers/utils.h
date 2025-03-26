/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:29:52 by afonsocouti       #+#    #+#             */
/*   Updated: 2025/03/26 15:07:23 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <stdint.h>

size_t	    ft_strlen(const char *s);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	    ft_strlcat(char *dst, const char *src, size_t dstsize);
char        *ft_strjoin(char const *s1, char const *s2);
ssize_t	    ft_fputstr(int fd, char *string);

char	    *ft_strdup(const char *s1);
char        *ft_strndup(const char *s1, size_t n);
bool        ft_isalpha(int c);
char	    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char        *ft_strstr(const char *haystack, const char *needle);

int	        ft_strncmp(const char *s1, const char *s2, size_t n);
int	        ft_strcmp(const char *s1, const char *s2);
void        ft_set_errno(int error);
long long	ft_atoll(const char *v);
bool        ft_isspace(char c);

bool        ft_isalnum(int c);
char    	*ft_strchr(const char *s, int c);
void    	*ft_calloc(size_t count, size_t size);
size_t      ft_strvlen(char **v);
char        **ft_strvjoin(char **v1, char **v2);

char	    **ft_split(const char *s, const char *c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_charjoin(char *str, char c);
char		*ft_itoa(int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char    	**ft_strvndup(char **v, size_t n);
char    	**ft_strvdup(char **v);
void    	ft_strvfree(char **v);
void		ft_bzero(void *s, size_t n);

#endif
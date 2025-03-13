/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:38:14 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 19:27:30 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_H
# define STRING_UTIL_H

# include <stdlib.h>
# include <errno.h>

char		*__join(const char *str1, const char *str2);
char		**__split(char const *s, char *c, int j, char **list);
char		*__copy_n(const char *str, int n);
char		*__str_trim(const char *str);
int			__equals(const char *str1, const char *str2);
int			__equals_n(const char *str1, const char *str2, int n);
int			__is_space(char c);
char		*__strnstr(const char *haystack, const char *needle, size_t len);
int			__size_list(char **list);
char		*__replace(const char *str1, const char *str2, const char *hey);
int			__isalpha(char c);
int			__isnumeric(char c);
int			__isalnum(char c);
char		**__split_spacer(char const *s, char *spacer);
char		*__itoa(long long n);
int			__atoi(const char *v);
long long	__atoll(const char *v);
ssize_t		__fputstr(int fd, char *string);
ssize_t		__fputnbr(int fd, long long number);
ssize_t		__count_list(char **lst);
char		**__join_list(char **lst1, char **lst2);
int			__starts_with(const char *str, const char *prefix);
size_t		ft_size(const char *s);

#endif

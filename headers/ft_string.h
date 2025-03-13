/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:38:14 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:27:39 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_string
{
	int			(*contains)(const char *str, const char *hey);
	size_t		(*size)(const char *s);
	char		*(*copy)(const char *str);
	char		*(*join)(const char *str1, const char *str2);
	char		*(*copy_n)(const char *str, int n);
	char		*(*trim)(const char *str);
	int			(*equals)(const char *str1, const char *str2);
	int			(*equals_n)(const char *str, const char *hey, int n);
	int			(*is_space)(char c);
	char		*(*strnstr)(const char *haystack,
			const char *needle, size_t len);
	int			(*size_list)(char **list);
	char		*(*replace)(const char *str1,
			const char *str2, const char *hey);
	int			(*isalpha)(char c);
	int			(*isnumeric)(char c);
	int			(*isalnum)(char c);
	char		**(*split)(char const *s, char *spacer);
	char		*(*itoa)(long long n);
	int			(*atoi)(const char *v);
	long long	(*atoll)(const char *v);
	int			(*isnumber)(const char *str);
	char		**(*copy_array_n)(char **values, long long n);
	ssize_t		(*fputstr)(int fd, char *string);
	ssize_t		(*fputnbr)(int fd, long long number);
	ssize_t		(*count_list)(char **lst);
	char		**(*join_list)(char **lst1, char **lst2);
}	t_string;

t_string	str(void);
char		*_str(const char c);
void		*ft_calloc(size_t __size);

#endif

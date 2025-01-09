/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/09 03:02:35 by afpachec         ###   ########.fr       */
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
	int			(*isalnum)(char c);
	char		**(*split)(char const *s, char *spacer);
	char		*(*itoa)(long long n);
	int			(*atoi)(const char *v);
	long long	(*atoll)(const char *v);
	int			(*isnumber)(const char *str);
	char		**(*copy_array_n)(char **values, long long n);
	ssize_t		(*fputstr)(int fd, char *string);
	ssize_t		(*fputnbr)(int fd, long long number);
}	t_string;

t_string	str(void);
char		*_str(const char c);
void		*ft_calloc(size_t __size);

#endif

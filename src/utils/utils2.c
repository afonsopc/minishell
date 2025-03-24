/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:35:55 by afonsocouti       #+#    #+#             */
/*   Updated: 2025/03/24 00:51:07 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (dup);
	i = -1;
	while (s1[++i])
		dup[i] = s1[i];
	dup[i] = '\0';
	return (dup);
}

char    *ft_strndup(const char *s1, size_t n)
{
    char    *dup;
    size_t  i;

    dup = malloc(n + 1);
    if (dup == NULL)
        return (dup);
    i = -1;
    while (s1[++i] && i < n)
        dup[i] = s1[i];
    dup[i] = '\0';
    return (dup);
}

bool	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

char    *ft_strstr(const char *haystack, const char *needle)
{
    return (ft_strnstr(haystack, needle, ft_strlen(haystack)));
}

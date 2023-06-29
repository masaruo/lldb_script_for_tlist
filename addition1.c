/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:11 by mogawa            #+#    #+#             */
/*   Updated: 2023/06/13 14:31:14 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	s1len;
	int	s2len;
	int	len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len <= s2len)
		len = s1len;
	else
		len = s2len;
	return (ft_strncmp(s1, s2, len));
}

void	ft_xfree(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*res;
	size_t	n;

	res = ft_xcalloc(len + 1, sizeof(char));
	n = 0;
	while (n < len)
	{
		res[n] = s[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}

size_t	ft_cntchar(const char *s, char c)
{
	size_t		n;

	n = 0;
	while (1)
	{
		if (*s != c && *s)
		{
			n++;
			while (*s != c && *s)
				s++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (n);
}

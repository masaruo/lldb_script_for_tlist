/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:17:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/08/18 15:59:14 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*heap_str;
	size_t	n;

	heap_str = ft_calloc(len + 1, sizeof(char));
	if (!heap_str)
		return (NULL);
	n = 0;
	while (n < len)
	{
		heap_str[n] = s[n];
		n++;
	}
	heap_str[n] = '\0';
	return (heap_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:09:55 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/07 22:46:03 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locates the first occurrence of the string needle in the string haystack
// 文字列haystack内において、文字列needleがあるかを検索し、該当箇所のポインタを返す。なければNULLを返す
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*h_stack;
	size_t		needle_len;

	h_stack = (char *) haystack;
	if (!*needle)
		return (h_stack);
	needle_len = ft_strlen(needle);
	while (len > 0 && *h_stack && len >= needle_len)
	{
		if (ft_strncmp(h_stack, needle, needle_len) == 0)
		{
			return (h_stack);
		}
		h_stack++;
		len--;
	}
	return (NULL);
}

// needle_len - 1
// abcHOGEd // HOGE // len = 6 // needle_len = 4
// 654321
//    x   | len = 3 // needle_len = 4 == No
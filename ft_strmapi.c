/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:12:06 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/07 22:58:32 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies func 'f' to each char of the string 's' to create new string
//!FREE必要　文字列ｓのそれぞれの文字に関数ｆを適応し、新たな文字列を返す
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*res;
	size_t		n;

	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (s[n])
	{
		res[n] = f(n, s[n]);
		n++;
	}
	res[n] = '\0';
	return (res);
}

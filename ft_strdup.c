/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:11:04 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/24 16:39:10 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
引数| 文字列（char const *s1）
戻り値| 新たに作り出された文字列へのポインタ
フリー| 必要
機能| 与えられた文字列に、領域を確保して、そのポインタを返す
*/
char	*ft_strdup(const char *s1)
{
	char		*res;
	size_t		n;

	n = ft_strlen(s1);
	res = ft_calloc((n + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (s1[n])
	{
		res[n] = s1[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}

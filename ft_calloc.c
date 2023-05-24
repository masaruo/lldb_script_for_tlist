/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:40 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/24 20:04:15 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
引数| カウント:count＆カウントあたりのサイズ:size_t size
戻り値| メモリー領域へのポインタ
フリー| 必要
機能| 0埋めしたメモリーを'size' x 'count'分確保
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*heap;
	size_t	amount;

	if (count == 0 || size == 0)
		return (NULL);
	if (count > SIZE_MAX / size)
		return (NULL);
	amount = count * size;
	heap = malloc(amount);
	if (heap == NULL)
		return (NULL);
	ft_bzero(heap, amount);
	return (heap);
}

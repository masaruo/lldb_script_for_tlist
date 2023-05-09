/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:40 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/09 12:16:47 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// alloc mem 'size' * 'count' filled with value zero
//!FREE必要 0埋めしたメモリーを'size' * 'count'分確保
void	*ft_calloc(size_t count, size_t size)
{
	void	*heap;
	size_t	amount;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	amount = count * size;
	heap = malloc(amount);
	if (heap == NULL)
		return (NULL);
	ft_bzero(heap, amount);
	return (heap);
}

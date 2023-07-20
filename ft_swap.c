/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:37:52 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/20 15:31:11 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_swap_int(int *a, int *b)
{
	int	tmp;

	if (!a || !b)
		return (EXIT_FAILURE);
	tmp = *a;
	*a = *b;
	*b = tmp;
	return (EXIT_SUCCESS);
}

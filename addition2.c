/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:37:52 by mogawa            #+#    #+#             */
/*   Updated: 2023/06/16 17:42:04 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_swap(int *a, int *b)
{
	int	tmp;

	if (!a || !b)
		return (0);
	tmp = *a;
	*a = *b;
	*b = tmp;
	return (0);
}

int	ft_get_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_get_min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

int	ft_get_abs(int a)
{
	if (a == INT_MIN)
		return (0);
	else if (a < 0)
		return (a * -1);
	else
		return (a);
}

int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

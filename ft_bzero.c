/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:38:09 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/07 22:30:26 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write n zeroed bytes to the string s.
// 文字列ｓにｎバイト分の０を書き込む
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

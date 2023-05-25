/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:35:12 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/24 16:46:46 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 文字ｃがアルファベットなら１を返し、それ以外は０を返す
int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	else
		return (0);
}

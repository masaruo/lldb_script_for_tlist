/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:56:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/25 09:42:34 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free_content(void *content)
{

	free (content);
}

void	ft_lst_free(t_list *list)
{
	ft_lstclear(&list, ft_lst_free_content);
}

/*
*param #1:	Number of elements
*param #2:	Size of elements
*param #3:	Pointer to t_list for address data
			NULL＊なら新たなリストを作成
*return:	A pointer to allocated memory
*func:		Allocates memory and fills it with zeros
*			address is stored to adrs linked list
*free:		Required
*/
void	*ft_lcalloc(size_t count, size_t size, t_list **adrs, int grp)
{
	t_list	*elem;
	t_mem	*mem;

	mem = ft_calloc(1, sizeof(t_mem));
	if (!mem)
	{
		//todo free all
		return (NULL);
	}
	mem->adr = ft_calloc(count, size);
	if (!mem->adr)
	{
		//todo free adrs
		return (NULL);
	}
	mem->grp = grp;
	elem = ft_lstnew(mem);
	if (!elem)
	{
		// todo free all
		return (NULL);
	}
	if (*adrs == NULL)
	{
		*adrs = elem;
	}
	else
	{
		ft_lstadd_back(adrs, elem);
	}
	return (mem->adr);
}

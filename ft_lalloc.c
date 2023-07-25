/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:56:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/25 15:19:39 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free_content(void *content)
{
	t_mem	*heap;

	heap = (t_mem *) content;
	free (heap->adr);
	free (content);
}

void	ft_lst_free(t_list **list)
{
	ft_lstclear(list, ft_lst_free_content);
}

/*
*param #1:	lcallocで確保されたメモリーアドレスのリスト
*param #2:	メモリーの指定グループ。−１(FREE_ALL)で全部のリストを削除
*return:	なし
*func:		確保されたリクンクドリストのメモリー領域をフリー
*free:		なし
*/
void	ft_lfree(t_list **head, int grp)
{
	t_list	*crnt;
	t_list	*prev;
	t_mem	*heap;

	prev = *head;
	crnt = prev->next;
	if (grp == FREE_ALL || prev->next == NULL)
		ft_lst_free(head);
	else
	{
		while (crnt != NULL)
		{
			heap = (t_mem *) crnt->content;
			if (heap->grp == grp)
			{
				prev->next = crnt->next;
				ft_lstdelone(crnt, ft_lst_free_content);
			}
			crnt = crnt->next;
		}
		if (ft_lstsize(*head) == 1)
			ft_lst_free(head);
	}
}

static t_mem	*ft_get_tmem_struct(size_t count, size_t size, int grp)
{
	t_mem	*mem;

	mem = ft_calloc(1, sizeof(t_mem));
	if (!mem)
	{
		return (NULL);
	}
	mem->adr = ft_calloc(count, size);
	if (!mem->adr)
	{
		free(mem);
		return (NULL);
	}
	mem->grp = grp;
	return (mem);
}

/*
*param #1:	エレメント数
*param #2:	各エレメントのサイズS
*param #3:	確保されたメモリーの住所を格納する
			リンクリスト。何もない場合はNULLを指して渡す
*return:	確保された領域へのポインタ
*func:		Allocates memory and fills it with zeros
*			address is stored to adrs linked list
*free:		必要
*/
void	*ft_lcalloc(size_t count, size_t size, t_list **adrs, int grp)
{
	t_list	*elem;
	t_mem	*mem;

	mem = ft_get_tmem_struct(count, size, grp);
	if (!mem)
		return (NULL);
	elem = ft_lstnew(mem);
	if (!elem)
	{
		//todo free
		return (NULL);
	}
	ft_lstadd_back(adrs, elem);
	return (mem->adr);
}

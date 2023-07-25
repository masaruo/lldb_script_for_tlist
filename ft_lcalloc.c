/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:56:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/25 17:44:41 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lfree_content(void *content)
{
	t_mem	*heap;

	heap = (t_mem *) content;
	free (heap->adr);
	heap->adr = NULL;
	free (content);
	content = NULL;
}

static void	ft_lfree_loop(t_list **head, int grp, void (*del)(void*))
{
	t_list	*crnt;
	t_list	*prev;
	t_list	*tmp;
	t_mem	*heap;

	prev = NULL;
	crnt = *head;
	while (crnt != NULL)
	{
		tmp = crnt->next;
		heap = (t_mem *) crnt->next;
		if (heap->grp == grp)
		{
			if (prev == NULL)
				*head = crnt->next;
			else
				prev->next = crnt->next;
			ft_lstdelone(crnt, del);
		}
		else
			prev = crnt;
		crnt = tmp;
	}
}

/*
*param #1:	lcallocで確保されたメモリーアドレスのリスト
*param #2:	メモリーの指定グループ。"FREE_ALL"で全部のリストを削除
*param #3:	contentをフリーする関数ポインタ。コンテンツ自体と
*			ヒープのアドレスだけの場合は"ft_free_content"を使用
*return:	なし
*func:		確保されたリクンクドリストのメモリー領域をフリー
*free:		なし
*/
void	ft_lfree(t_list **head, int grp, void (*del)(void*))
{
	if (grp == FREE_ALL)
	{
		ft_lstclear(head, del);
	}
	else
	{
		ft_lfree_loop(head, grp, del);
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
*param #3:	確保されたメモリーの住所を格納するリンクリスト。
*			初期化の場合はNULLポインターとして渡す
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
		free(mem->adr);
		free(mem);
		return (NULL);
	}
	ft_lstadd_back(adrs, elem);
	return (mem->adr);
}

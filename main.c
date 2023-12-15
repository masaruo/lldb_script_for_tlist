/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:45:42 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/15 21:13:59 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef	struct	s_data
{
	int		_int;
	char	*_str;
}				t_data;

t_list	*get_data(void)
{
	t_list		*head;
	t_data		*content;

	head = ft_lstnew(NULL);
	content = calloc(1, sizeof(t_data));
	content->_int = -100;
	content->_str = strdup("Hello World");
	ft_lstadd_back(&head, ft_lstnew(content));
	content = calloc(1, sizeof(t_data));
	content->_int = 0;
	content->_str = strdup("from 42 Tokyo!");
	ft_lstadd_back(&head, ft_lstnew(content));
	content = calloc(1, sizeof(t_data));
	content->_int = 42;
	content->_str = strdup("This programe will create memory leak!");
	ft_lstadd_back(&head, ft_lstnew(content));
	return (head);
}

int	main(void)
{
	t_list	*head_of_tlist;

	head_of_tlist = get_data();
	(void)head_of_tlist;// surpress a compiler's warning
	return (0);
}

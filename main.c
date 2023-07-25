#include "libft.h"

void test(void)
{
	t_list	*head;
	int		*arr;
	int		*arr2;
	char	*str;

	head = NULL;
	arr = ft_lcalloc(5, sizeof(int), &head, 0);
// printf("addr %p\n", adrs);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr2 = ft_lcalloc(2, sizeof(int), &head, 1);
	arr2[0] = 99;
	arr2[1] = 88;
	str = ft_lcalloc(3, sizeof(char), &head, 2);
	str[0] = 'h';
	str[1] = 'i';
	str[2] = '\0';
	for (int i = 0; i < 5; i++)
		printf("arr[i]=%d\n", arr[i]);
	// ft_lfree(&head, 0, ft_lfree_content);
	for (int j = 0; j < 2; j++)
		printf("arr[j]=%d\n", arr2[j]);
	// ft_lfree(&head, 1, ft_lfree_content);
	printf("%s\n", str);
	// ft_lfree(&head, 2, ft_lfree_content);
	ft_lfree(&head, FREE_ALL, ft_lfree_content);
	printf("lstsize:%d\n", ft_lstsize(head));
	printf("addr %p\n", head);
	return ;
}

int main (void)
{
	test();
	system("leaks -q a.out");
	return (0);
}
#include "libft.h"

typedef struct s_inner
{
	int		*in_int_arr;
	char	*in_char_arr;
}	t_inner;

typedef struct s_test
{
	int		*int_arr;
	char	*char_arr;
	t_inner	*in;
}	t_test;

void test(void)
{
	t_list	*head;
	int		*arr;
	int		*arr2;
	char	*str;

	// head = NULL;
	arr = ft_lcalloc(5, sizeof(int), &head, INIT);
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
	for (int j = 0; j < 2; j++)
		printf("arr[j]=%d\n", arr2[j]);
	ft_lfree(&head, 1);
	for (int i = 0; i < 5; i++)
		printf("arr[i]=%d\n", arr[i]);
	ft_lfree(&head, 0);
	printf("%s\n", str);
	ft_lfree(&head, 2);
	// ft_lfree(&head, FREE_ALL);
	printf("lstsize:%d\n", ft_lstsize(head));
	// printf("addr %p\n", head);
	// ft_lfree(&head, ALL);
	return ;
}

void	test_struct(void)
{
	t_inner	*indata;
	t_test	*test;
	t_list	*head;

	// head = NULL;
	indata = ft_lcalloc(1, sizeof(t_inner), &head, 0);
	indata->in_char_arr = ft_lcalloc(3, sizeof(char), &head, 0);
	indata->in_char_arr[0] = 'h';
	indata->in_char_arr[1] = 'i';
	indata->in_char_arr[2] = '\0';
	//!
	indata->in_int_arr = ft_lcalloc(3, sizeof(int), &head, 1);
	indata->in_int_arr[0] = 1;
	indata->in_int_arr[1] = 2;
	indata->in_int_arr[2] = 3;
	//!
	test = ft_lcalloc(1, sizeof(t_test), &head, 5);
	test->in = indata;
	test->char_arr = ft_lcalloc(3, sizeof(char), &head, 3);
	test->char_arr[0] = 'H';
	test->char_arr[1] = 'i';
	test->char_arr[2] = '\0';
	//!
	test->int_arr = ft_lcalloc(3, sizeof(int), &head, 4);
	test->int_arr[0] = 999;
	test->int_arr[1] = 888;
	test->int_arr[2] = 777;
	//!
	printf("indata->in_char_arr:%s\n", test->in->in_char_arr);
	printf("test->char_arr:%s\n", test->char_arr);
	for (int i = 0; i < 3; i++)
		printf("indata_intarr:%d\n", test->in->in_int_arr[i]);
	for (int i = 0; i < 3; i++)
		printf("test_intarr:%d\n", test->int_arr[i]);
	printf("listNum=%d\n", ft_lstsize(head));
	ft_lfree(&head, 0);
	// ft_lfree(&head, 1);
	ft_lfree(&head, 2);
	ft_lfree(&head, 3);
	ft_lfree(&head, 4);
	ft_lfree(&head, 5);
	ft_lfree(&head, ALL);
	printf("listNum=%d\n", ft_lstsize(head));
}

int main (void)
{
	test();
	test_struct();
	system("leaks -q a.out");
	return (0);
}
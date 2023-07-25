#include "libft.h"

int main(void)
{
	t_list	*adrs;
	int		*arr;

	adrs = NULL;
	arr = ft_lcalloc(5, sizeof(int), &adrs, 0);
printf("addr %p\n", adrs);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	for (int i = 0; i < 5; i++)
		printf("arr[i]=%d\n", arr[i]);
	ft_lst_free(adrs);
	printf("addr %p\n", adrs);
	system("leaks -q a.out");
	return (0);
}
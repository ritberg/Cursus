#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

int	main()
{
/*
	t_list	*first;
	t_list	*second;
	first = ft_new_node("One");
	second = ft_new_node("Two");
	printf("%d\n", ft_list_size("Yes"));
	printf("%d\n", ft_list_size("No"));
*/

	return (0);
}


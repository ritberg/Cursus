#include "list.h"
#include "stdio.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*temp;
	int	c;

	temp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data))
			lst->next;
		else
		{
			c = lst->data;
			lst->data = lst->next->data;
			lst->next->data = c;
			lst = temp;
		}
	}
	//lst = temp;
	return (lst);
}

/* an other option

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);

*/


/*
int	main(int argc, char **argv)
{

	t_list	*lst;
	t_list	*tmp;

	lst = create_pile(argc, argv);
	tmp = lst;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
*/

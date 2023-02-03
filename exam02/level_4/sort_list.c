#include "list.h"
#include "stdlib.h"
#include "stdio.h"

// right answer:

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
}

/* I wrote at the exam

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*temp;
	int	c;

	temp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data))
			lst = temp->next;
		else
		{
			c = lst->data;
			lst->data = lst->next->data;
			lst->next->data = c;
			lst = temp->next; // lst = temp why??
		}
	}
	//lst = temp; why??
	return (lst);
}
*/





/* TEST

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\v' || c == '\f' || c == '\r');
}



static long long int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

t_list	*ft_lstnew_int(int data) // lstnew of libft. int instead of void *
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}


t_list	*create_pile(int argc, char **argv)
{
	int			j;
	long long	a;
	t_list		*pile;
	t_list		*new_elem;

	j = argc - 1;
	pile = NULL;
	while (j >= 1)
	{
		a = ft_atoi(argv[j]);
		new_elem = ft_lstnew_int(a);
		new_elem->next = pile;
		pile = new_elem;
		j--; // the first argv[i] is on the top
	}
	return (pile);
}

int ascending(int a, int b)
{
	return (a <= b);
}

int	main(int argc, char **argv)
{

	t_list	*lst;
	t_list	*tmp;

	lst = create_pile(argc, argv);
	tmp = lst;
	sort_list(tmp, ascending);
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
*/

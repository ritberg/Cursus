#include "push_swap.h"

//print struct
void	printlist(t_list *head)
{
	t_list	*temporary = head;

	printf("%s\n", "Pile A");
	while (temporary != NULL)
	{
		printf("%d\n", temporary->content);
		temporary = temporary->next;
	}
}

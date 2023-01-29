#include "ft_list.h" // without #ifndef #endif !
#include "stdlib.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*saved;


	if (*begin_list == NULL || begin_list == NULL)
		return;

	*saved = *begin_list;
	if (cmp(saved->data, data_ref) == 0) // why not *cmp?
	{
		*begin_list = saved->next;
		free(saved);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	saved = *begin_list;
	ft_list_remove_if(&saved->next, data_ref, cmp); // why this?
}

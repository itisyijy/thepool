//#include "ft_list.h"
#include <stdlib.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void*, void*))
{
	int i = 0;
	t_list *tmp;

	if (begin_list && *begin_list)
	{
		if (cmp((*begin_list)->data, data_ref) == 0)
		{
			tmp = (*begin_list)->next;
			begin_list = &tmp;
			free(*begin_list);
		}
		while ((*begin_list)->next != NULL)
		{
			if (cmp((*begin_list)->next->data, data_ref))
			{}
				(*begin_list)->next = (*begin_list)->next->next;
				free((*begin_list)->next);
			}
		}

        // t_list  *tmp;
        // t_list  *i;

        // i = *begin_list;
		// while (*begin_list && !cmp((*begin_list)->data, data_ref))
		// {
		// 	tmp = *begin_list;	
		// 	*begin_list = (*begin_list)->next;
		// 	free(tmp);
		// }
		// i = *begin_list;
		// while (i && i->next)
		// {
		// 	if (!cmp(i->next->data, data_ref))
		// 	{
		// 		tmp = i->next;
		// 		i->next = tmp->next;
		// 		free(tmp);
		// 	}
		// 	if (i->next)
		// 		i = i->next;
		// }
}

#include <stdio.h>

int cmp(void *a, void *b)
{
	if (a == b)
		return (0);
	return (1);
}
#include <stdio.h>
int main()
{
	char arr1[] = "AAA";
	char arr2[] = "BBB";
	char arr3[] = "CCC";
	char arr4[] = "DDD";
	char arr5[] = "EEE";

	t_list list5 = {(void *)arr5, 0};
	t_list list4 = {(void *)arr4, &list5};
	t_list list3 = {(void *)arr3, &list4};
	t_list list2 = {(void *)arr2, &list3};
	t_list list1 = {(void *)arr1, &list2};

	t_list *list = &list1;
	//char data[] = "CCC";
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", list->data);
		list = list->next;
	}	
	ft_list_remove_if(&list, (void *)arr2, cmp);
	list = &list1;
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", list->data);
		list = list->next;
	}	
}

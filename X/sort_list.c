typedef struct s_list
{
    int data;
    struct s_list *next;
} t_list;

int count_element(t_list *lst)
{
    int count = 0;
    while (lst->next != 0)
    {
	count++;
	lst = lst->next;
    }
    count++;
    return (count);
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int	i = 0;
    t_list *tmp;
    if (lst == 0)
	return (0);
    int count = count_element(lst);
    while (i < count)
    {
	tmp = lst;
	while ((*tmp).next != 0)
	{
	    if (cmp((tmp->data), (tmp->next->data)) != 0)
	    {
		int s = (tmp->data);
		(tmp->data) = (tmp->next->data);
		(tmp->next->data) = s;
	    }
	    tmp = tmp->next;
	}
	i++;
    }
    return (lst);
}

#include <stdio.h>
int ascending(int a, int b)
{
    return (a <= b);
}

int main()
{
    t_list list5 = {1, 0};
    t_list list4 = {2, &list5};
    t_list list3 = {3, &list4};
    t_list list2 = {4, &list3};
    t_list list1 = {5, &list2};

    sort_list(&list1, ascending);
}

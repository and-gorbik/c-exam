#include "check_mate.h"

void			free_figures(t_figure **lst)
{
	t_figure	*cur;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		cur = cur->next;
		free(*lst);
		*lst = cur;
	}
}

t_figure		*new_figure(char type, int i, int j)
{
	t_figure	*item;

	if (!(item = malloc(sizeof(t_figure))))
		return (NULL);
	item->type = type;
	item->i = i;
	item->j = j;
	item->next = NULL;
	return (item);	
}

t_figure		*add_figure(t_figure *first, char type, int i, int j)
{
	t_figure	*item;

	if (!(item = new_figure(type, i, j)))
	{
		free_figures(&first);
		return (NULL);
	}
	item->next = first;
	first = item;
	return (first);
}
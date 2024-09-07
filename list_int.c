/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:43 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:00:02 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*ft_lstnew_int(int value)
{
	t_nodes	*new;

	new = malloc(sizeof(t_nodes));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_nodes	*ft_lstnew_index(int index)
{
	t_nodes	*new;

	new = malloc(sizeof(t_nodes));
	if (!new)
		return (NULL);
	new->index = index;
	new->next = NULL;
	return (new);
}

t_nodes	*ft_lstlast_int(t_nodes *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_int(t_nodes **lst, t_nodes *new)
{
	t_nodes	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_int(*lst);
	tmp->next = new;
}

int	ft_lstsize_int(t_nodes *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

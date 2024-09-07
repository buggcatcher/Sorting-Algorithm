/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:59:13 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:00:46 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprev(t_nodes *head)
{
	t_nodes	*current;
	t_nodes	*previous;

	current = head;
	previous = NULL;
	while (current != NULL)
	{
		current->prev = previous;
		previous = current;
		current = current->next;
	}
}

int	ft_lstlast_index(t_nodes *head)
{
	t_nodes	*current;

	current = head;
	if (current == NULL)
	{
		return (-1);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current->index);
}

t_nodes	*ft_lstmin_index(t_nodes *stack)
{
	t_nodes	*current;
	t_nodes	*min;

	current = stack;
	min = stack;
	while (current != NULL)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}

void	ft_lstclear_int(t_nodes **lst)
{
	t_nodes	*current;
	t_nodes	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

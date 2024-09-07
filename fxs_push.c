/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxs_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:56:05 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/01 12:34:19 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_nodes **stack_from, t_nodes **stack_to)
{
	t_nodes	*tmp;
	t_nodes	*head_to;
	t_nodes	*head_from;

	if (ft_lstsize_int(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_nodes **stack_a, t_nodes **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	return (0);
}

int	pb(t_nodes **stack_a, t_nodes **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	return (0);
}

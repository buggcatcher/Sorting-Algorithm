/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxs_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:25:32 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 18:49:18 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_nodes **stack_a)
{
	t_nodes	*first;
	t_nodes	*second;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	return (1);
}

int	sb(t_nodes **stack_b)
{
	t_nodes	*first;
	t_nodes	*second;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	return (1);
}

int	ss(t_nodes **stack_a, t_nodes **stack_b)
{
	int	result_a;
	int	result_b;

	result_a = sa(stack_a);
	result_b = sb(stack_b);
	return (result_a && result_b);
}

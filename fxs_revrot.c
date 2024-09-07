/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxs_revrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:02:15 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 18:46:58 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_nodes **stack_a)
{
	t_nodes	*prev;
	t_nodes	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_nodes **stack_b)
{
	t_nodes	*prev;
	t_nodes	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrr(t_nodes **stack_a, t_nodes **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

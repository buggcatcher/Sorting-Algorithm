/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:32 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 18:44:11 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_rrb(t_moves *moves, t_nodes **stack_b)
{
	while (moves->rrb > 0)
	{
		rrb(stack_b);
		ft_putendl_fd("rrb", 1);
		moves->rrb--;
	}
}

void	execute_rotations(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b)
{
	if (moves->ra < moves->rra)
	{
		while (moves->ra > 0 && moves->rb > 0 && moves->rb < moves->rrb)
			perform_rr(moves, stack_a, stack_b);
		while (moves-> ra > 0)
			perform_ra(moves, stack_a);
	}
	else
	{
		while (moves->rra > 0 && moves->rrb > 0 && moves->rrb < moves->rb)
			perform_rrr(moves, stack_a, stack_b);
		while (moves->rra > 0)
			perform_rra(moves, stack_a);
	}
	if (moves->rb < moves->rrb)
	{
		while (moves->rb > 0)
			perform_rb(moves, stack_b);
	}
	else
	{
		while (moves->rrb > 0)
			perform_rrb(moves, stack_b);
	}
}

void	rotate_to_min(t_nodes **stack_a)
{
	int		min_index;
	int		distance_from_head;
	t_nodes	*current;

	min_index = find_min_index(*stack_a);
	distance_from_head = calculate_distance_from_head(*stack_a, min_index);
	current = *stack_a;
	if (distance_from_head > ft_lstsize_int(*stack_a) / 2)
	{
		while (current->index != min_index)
		{
			rra(stack_a);
			ft_putendl_fd("rra", 1);
			current = *stack_a;
		}
	}
	else
	{
		while (current->index != min_index)
		{
			ra(stack_a);
			ft_putendl_fd("ra", 1);
			current = *stack_a;
		}
	}
}

int	find_min_index(t_nodes *stack)
{
	int		min_index;
	t_nodes	*current;

	min_index = stack->index;
	current = stack;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

int	check_order(t_nodes *stack)
{
	t_nodes	*current;

	current = stack;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rotations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:33:47 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 18:45:21 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_rr(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b)
{
	while (moves->ra > 0 && moves->rb > 0)
	{
		rr(stack_a, stack_b);
		ft_putendl_fd("rr", 1);
		moves->ra--;
		moves->rb--;
	}
}

void	perform_ra(t_moves *moves, t_nodes **stack_a)
{
	while (moves->ra > 0)
	{
		ra(stack_a);
		ft_putendl_fd("ra", 1);
		moves->ra--;
	}
}

void	perform_rrr(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b)
{
	while (moves->rra > 0 && moves->rrb > 0)
	{
		rrr(stack_a, stack_b);
		ft_putendl_fd("rrr", 1);
		moves->rra--;
		moves->rrb--;
	}
}

void	perform_rra(t_moves *moves, t_nodes **stack_a)
{
	while (moves->rra > 0)
	{
		rra(stack_a);
		ft_putendl_fd("rra", 1);
		moves->rra--;
	}
}

void	perform_rb(t_moves *moves, t_nodes **stack_b)
{
	while (moves->rb > 0)
	{
		rb(stack_b);
		ft_putendl_fd("rb", 1);
		moves->rb--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00:58 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:34:19 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_1(t_nodes **stack_a)
{
	sa(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sort_case_2(t_nodes **stack_a)
{
	sa(stack_a);
	ft_putendl_fd("sa", 1);
	rra(stack_a);
	ft_putendl_fd("rra", 1);
}

void	sort_case_3(t_nodes **stack_a)
{
	ra(stack_a);
	ft_putendl_fd("ra", 1);
}

void	sort_case_4(t_nodes **stack_a)
{
	sa(stack_a);
	ft_putendl_fd("sa", 1);
	ra(stack_a);
	ft_putendl_fd("ra", 1);
}

void	sort_case_5(t_nodes **stack_a)
{
	rra(stack_a);
	ft_putendl_fd("rra", 1);
}

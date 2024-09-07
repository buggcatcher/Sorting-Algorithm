/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:20:50 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 20:14:30 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks_part1(int argc, char **argv, int *free_flag, \
char ***args)
{
	*free_flag = 0;
	check_for_letters(argv);
	*args = ft_arg_checker(argc, argv);
	if (argc == 1)
		exit (1);
	if (argc == 2 && *args != argv)
		*free_flag = 1;
}

void	initialize_stacks_part2(t_nodes **stack_a, t_nodes **stack_b, \
char **args)
{
	*stack_a = ft_createstack_a(args);
	*stack_b = NULL;
}

int	handle_memory_allocation(void *array, int free_flag, void *args)
{
	if (!array)
	{
		write(2, "Error: Memory allocation failed\n", 32);
		if (free_flag)
			free(args);
		return (1);
	}
	return (0);
}

void	sort_stacks(t_nodes **stack_a, t_nodes **stack_b)
{
	t_moves	moves;

	ft_sort3(stack_a);
	ft_lstprev(*stack_a);
	ft_lstprev(*stack_b);
	while (*stack_b != NULL)
	{
		moves.ra = 0;
		moves.rb = 0;
		moves.rra = 0;
		moves.rrb = 0;
		moves.totmoves = 0;
		target_distance(&moves, *stack_a, *stack_b);
		execute_rotations(&moves, stack_a, stack_b);
		pa(stack_a, stack_b);
		ft_putendl_fd("pa", 1);
	}
}

void	populate_array(t_nodes *stack_a, int *array)
{
	t_nodes	*current;
	size_t	i;

	current = stack_a;
	i = 0;
	while (current != NULL)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
}

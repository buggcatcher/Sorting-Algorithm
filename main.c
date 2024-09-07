/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:52:26 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 20:14:19 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*ft_createstack_a(char **args)
{
	t_nodes	*stack_a;
	t_nodes	*value;
	int		num;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i] != NULL)
	{
		num = ft_atoi_minmax(args[i]);
		value = ft_lstnew_int(num);
		if (!value)
			error_handler("mem");
		ft_lstadd_back_int(&stack_a, value);
		i++;
	}
	return (stack_a);
}

int	ft_create_temp_array(t_nodes *stack, int **array)
{
	int		len;
	t_nodes	*current;
	int		i;

	len = ft_lstsize_int(stack);
	current = stack;
	i = 0;
	*array = malloc(sizeof(int) * len);
	if (!*array)
		error_handler("mem");
	while (current)
	{
		(*array)[i++] = current->value;
		current = current->next;
	}
	return (i);
}

void	initialize(int argc, char **argv, t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->temp_array = NULL;
	data->len = 0;
	data->array = NULL;
	ft_atoi_minmax(argv[1]);
	initialize_stacks_part1(argc, argv, &data->free_flag, &data->args);
	initialize_stacks_part2(&data->stack_a, &data->stack_b, data->args);
	validate_stack(data->stack_a, data->free_flag, data->args);
	data->stack_size = ft_lstsize_int(data->stack_a);
	data->array = malloc(sizeof(int) * data->stack_size);
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialize(argc, argv, &data);
	handle_memory_allocation(data.array, data.free_flag, *data.args);
	populate_array(data.stack_a, data.array);
	ft_create_temp_array(data.stack_a, &data.temp_array);
	process_stack(data.stack_a, &data.temp_array);
	push_chunks(&data.stack_a, &data.stack_b, data.stack_size);
	sort_stacks(&data.stack_a, &data.stack_b);
	rotate_to_min(&data.stack_a);
	cleanup(&data);
	return (0);
}

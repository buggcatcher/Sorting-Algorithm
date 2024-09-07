/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:57:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:07:03 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	error_handler(const char *error_type)
{
	if (strcmp(error_type, "mem") == 0)
		write(2, "Error: Memory allocation failed\n", 32);
	else if (strcmp(error_type, "invalid") == 0)
		write(2, "Error: Invalid arguments\n", 25);
	else if (strcmp(error_type, "usage") == 0)
		write(2, "Usage: ./push_swap <numbers>\n", 29);
	else if (strcmp(error_type, "range") == 0)
		write(2, "Error: Number out of range\n", 27);
	else if (strcmp(error_type, "char") == 0)
		write(2, "Error: Only numbers allowed\n", 28);
	else if (strcmp(error_type, "dup") == 0)
		write(2, "Error: Contains duplicate\n", 26);
	else if (strcmp(error_type, "order") == 0)
		write(2, "Error: stack already ordered\n", 30);
	else if (strcmp(error_type, "no_stack") == 0)
		write(2, "Error: No stack found\n", 23);
	exit(1);
}

int	ft_isdup(int num, char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (j != i && ft_atoi_minmax(argv[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

char	**ft_arg_checker(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	check_range(argc, argv);
	args = ft_usage_check(argc, argv);
	while (args[++i])
	{
		if (!ft_isnum(args[i]))
		{
			if (argc == 2)
				free_split(args);
			error_handler("char");
		}
		tmp = ft_atoi_minmax(args[i]);
		if (ft_isdup(tmp, args, i))
		{
			if (argc == 2)
				free_split(args);
			error_handler("dup");
		}
	}
	return (args);
}

int	validate_stack(t_nodes *stack_a, int free_flag, char **args)
{
	t_nodes	*temp;

	if (ft_order_check(stack_a) || ft_lstsize_int(stack_a) == 1)
	{
		while (stack_a)
		{
			temp = stack_a;
			stack_a = stack_a->next;
			free(temp);
		}
		if (free_flag)
			free_split(args);
		error_handler("order");
	}
	if (!stack_a)
	{
		if (free_flag)
			free_split(args);
		error_handler("no_stack");
	}
	return (0);
}

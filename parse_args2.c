/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:15:40 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:08:54 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_order_check(t_nodes *stack)
{
	t_nodes	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	if (current != NULL)
		return (1);
	return (0);
}

char	**ft_usage_check(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error_handler("mem");
		if (args[0] == NULL)
		{
			free_args(args);
			error_handler("invalid");
		}
	}
	else
	{
		if (argc == 1)
			error_handler("usage");
		args = argv + 1;
	}
	return (args);
}

void	check_for_letters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
			{
				error_handler("char");
			}
			j++;
		}
		i++;
	}
}

void	check_range(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error_handler("mem");
	}
	else
	{
		args = argv + 1;
	}
	validate_range(argc, args);
	if (argc == 2)
		free_args(args);
}

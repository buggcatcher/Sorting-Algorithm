/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:11:23 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:11:04 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_sign(const char *str, int *index)
{
	int	sign;
	int	count_minus;

	sign = 1;
	count_minus = 0;
	while (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			count_minus++;
		(*index)++;
	}
	if (count_minus % 2 != 0)
		sign = -1;
	return (sign);
}

unsigned long	parse_number(const char *str, int *index)
{
	unsigned long	result;

	result = 0;
	while (ft_isdigit(str[*index]))
	{
		if (result > (unsigned long)INT_MAX)
		{
			error_handler("range");
		}
		result = result * 10 + str[*index] - '0';
		if (result > (unsigned long)INT_MAX)
		{
			error_handler("range");
		}
		(*index)++;
	}
	return (result);
}

int	ft_atoi_minmax(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	sign = parse_sign(str, &i);
	result = parse_number(str, &i);
	if (sign == -1 && result > (unsigned long)INT_MIN)
	{
		error_handler("range");
	}
	return (sign * (int)result);
}

int	is_number_too_large(const char *str)
{
	int	len;

	len = strlen(str);
	if (len > 11)
		return (1);
	if (len == 11 && str[0] != '-')
		return (1);
	return (0);
}

void	validate_range(int argc, char **args)
{
	int		i;
	long	tmp;

	i = 0;
	while (args[i])
	{
		if (is_number_too_large(args[i]))
		{
			if (argc == 2)
				free_args(args);
			error_handler("range");
		}
		tmp = ft_atoi_minmax(args[i]);
		if (tmp <= INT_MIN || tmp >= INT_MAX)
		{
			if (argc == 2)
				free_args(args);
			error_handler("range");
		}
		i++;
	}
}

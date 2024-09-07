/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:31:02 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:35:23 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_left(int arr[], int temp_left[], int left, int low)
{
	int	i;

	i = 0;
	while (i < left)
	{
		temp_left[i] = arr[low + i];
		i++;
	}
}

void	fill_right(int arr[], int temp_right[], int right, int middle)
{
	int	i;

	i = 0;
	while (i < (right))
	{
		temp_right[i] = arr[middle + 1 + i];
		i++;
	}
}

int	create_arrays(int left, int right, int **temp_left, int **temp_right)
{
	*temp_left = malloc(sizeof(int) * left);
	if (!temp_left)
	{
		printf("ERROR: temp_left allocation failed");
		return (-1);
	}
	*temp_right = malloc(sizeof(int) * right);
	if (!temp_right)
	{
		free(temp_left);
		printf("ERROR: temp_right allocation failed");
		return (-1);
	}
	return (0);
}

int	cold_start(int arr[], t_nodes **list_a, int length)
{
	t_nodes	*current;
	int		index;

	current = *list_a;
	merge_sort(arr, length);
	index = 0;
	while (index + 1 < length)
	{
		if ((arr)[index] == (arr)[index + 1])
			return (1);
		index++;
	}
	while (current != NULL)
	{
		index = binary_search(arr, current->value, 0, length);
		if (index < 0)
			return (-1);
		current->index = index;
		current = current->next;
	}
	return (0);
}

void	merge_sort_recursion(int arr[], int low, int high)
{
	int	middle;

	if (low >= high)
		return ;
	middle = low + (high - low) / 2;
	merge_sort_recursion(arr, low, middle);
	merge_sort_recursion(arr, middle + 1, high);
	merge_sorted_arrays(arr, low, middle, high);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:34:27 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 19:36:51 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sorted_arrays(int arr[], int low, int middle, int high)
{
	int	i;
	int	j;
	int	k;
	int	*temp_left;
	int	*temp_right;

	i = create_arrays(middle - low + 1, high - middle, &temp_left, &temp_right);
	if (i == -1)
		return ;
	fill_left(arr, temp_left, middle - low + 1, low);
	fill_right(arr, temp_right, high - middle, middle);
	i = low;
	j = 0;
	k = 0;
	while (i <= high)
	{
		if ((j < (middle - low + 1)) && (k >= (high - middle)
				|| temp_left[j] <= temp_right[k]))
			arr[i] = temp_left[j++];
		else
			arr[i] = temp_right[k++];
		i++;
	}
	free(temp_left);
	free(temp_right);
}

int	binary_search(int arr[], int target, int low, int high)
{
	int	i;

	i = (low + high) / 2;
	if (arr[i] == target)
		return (i);
	if (low >= high)
		return (-1);
	if (arr[i] < target)
		return (binary_search(arr, target, i + 1, high));
	if (arr[i] > target)
		return (binary_search(arr, target, low, i - 1));
	return (i);
}

int	*sort_temp_array(int arr[], int length)
{
	int	i;
	int	*sorted_array;

	merge_sort(arr, length);
	sorted_array = (int *)malloc(sizeof(int) * length);
	if (!sorted_array)
	{
		printf("ERROR: Allocation for sorted_array failed\n");
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		sorted_array[i] = arr[i];
		i++;
	}
	return (sorted_array);
}

void	assign_indices(t_nodes *stack_a, int *sorted_array, int length)
{
	t_nodes	*current;
	int		index;

	current = stack_a;
	while (current != NULL)
	{
		index = 0;
		while (index < length)
		{
			if (sorted_array[index] == current->value)
			{
				current->index = index;
				break ;
			}
			index++;
		}
		current = current->next;
	}
}

void	merge_sort(int arr[], int length)
{
	merge_sort_recursion(arr, 0, length - 1);
}

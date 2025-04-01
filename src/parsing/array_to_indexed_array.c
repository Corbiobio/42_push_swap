/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_indexed_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:51:45 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/26 18:12:29 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	replace_by_index_sorted(int *arr, int *arr_index, int len, int num)
{
	int	smallest_index;
	int	smallest_num;
	int	i;

	smallest_index = 0;
	while (arr_index[smallest_index] != 0)
		smallest_index++;
	smallest_num = arr[smallest_index];
	i = smallest_index + 1;
	while (i < len)
	{
		if (arr[i] < smallest_num && arr_index[i] == 0)
		{
			smallest_num = arr[i];
			smallest_index = i;
		}
		i++;
	}
	arr_index[smallest_index] = num;
}

static int	*replace_all_by_index_sorted(int *arr, int *arr_index, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		replace_by_index_sorted(arr, arr_index, len, i + 1);
		i++;
	}
	return (arr_index);
}

int	*array_to_indexed_array(int *array, int len)
{
	int	*indexed_arr;

	indexed_arr = ft_calloc(len, sizeof(int));
	if (indexed_arr == NULL)
	{
		free(array);
		error_exit();
	}
	indexed_arr = replace_all_by_index_sorted(array, indexed_arr, len);
	free(array);
	return (indexed_arr);
}

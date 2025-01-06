/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_indexed_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:51:45 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/06 11:55:46 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	*arg_to_arr(int argc, char **argv, int to_free)
{
	int	i;
	int	j;
	int	*arr;

	arr = malloc(sizeof(int) * argc);
	i = argc - 1;
	while (i >= 0 && arr != NULL)
	{
		arr[i] = ft_atoi(argv[argc - (i + 1)]);
		j = i + 1;
		while (j < argc)
		{
			if (arr[j] == arr[i])
			{
				if (to_free == 1)
					free_argv(argv);
				free(arr);
				error_exit();
			}
			j++;
		}
		i--;
	}
	return (arr);
}

static void	replace_one_by_index_sorted(int *arr, int *arr_index, int len, int n)
{
	int	smallest_index;
	int	smallest;
	int	i;

	smallest_index = 0;
	while (smallest_index < len)
	{
		if (arr_index[smallest_index] == 0)
			break ;
		smallest_index++;
	}
	smallest = arr[smallest_index];
	i = smallest_index + 1;
	while (i < len)
	{
		if (arr[i] < smallest && arr_index[i] == 0)
		{
			smallest = arr[i];
			smallest_index = i;
		}
		i++;
	}
	arr_index[smallest_index] = n;
}

static int	*replace_all_by_index_sorted(int *arr, int *arr_index, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		replace_one_by_index_sorted(arr, arr_index, len, i + 1);
		i++;
	}
	return (arr_index);
}

int	*arg_to_indexed_arr(int *argc, char **argv)
{
	int	*arr;
	int	*arr_index;
	int	to_free;

	to_free = 0;
	argv = parse_arg(argc, argv, &to_free);
	arr = arg_to_arr(*argc, argv, to_free);
	if (to_free == 1)
		free_argv(argv);
	arr_index = ft_calloc(*argc, sizeof(int));
	if (arr != NULL && arr_index != NULL)
		arr_index = replace_all_by_index_sorted(arr, arr_index, *argc);
	else
	{
		if (arr_index == NULL)
			free(arr_index);
		if (arr == NULL)
			free(arr);
		error_exit();
	}
	free(arr);
	return (arr_index);
}

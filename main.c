/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/05 18:08:07 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	push_swap(int argc, int *arr)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	a = init_stack('a', argc, arr);
	b = init_stack('b', argc, NULL);
	op = NULL;
	push_op(&op, NULL, '0');
	op_start = op;
	if (a.arr != NULL && b.arr != NULL && op != NULL)
	{
		sort(&a, &b, &op);
		print_op(op_start->next);
	}
	else
		error();
	free_all(&a, &b, op_start);
}

int	*arg_to_arr(int argc, char **argv, int to_free)
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

void replace_by_index_sorted(int *arr, int *arr_index, int len, int n)
{
	int	smallest_index;
	int	smallest;
	int	i;

	smallest_index = 0;
	while (smallest_index < len)
	{
		if (arr_index[smallest_index] == 0)
			break;
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
	printf("%d ", smallest);
	arr_index[smallest_index] = n;
}

int	*replace_all_by_index_sorted(int *arr, int *arr_index, int len)
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

int	*parse_arg_to_arr(int *argc, char **argv)
{
	int	*arr;
	int	*arr_index;
	int	to_free;
	int	i;

	to_free = 0;
	argv = parse_arg(argc, argv, &to_free);
	arr = arg_to_arr(*argc, argv, to_free);
	if (to_free == 1)
		free_argv(argv);
	arr_index = malloc(sizeof(int) * (*argc));
	if (arr_index != NULL)
		ft_bzero(arr_index, *argc);
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
	i = 0;
	while (i < *argc)
	{
		printf("%d ", arr_index[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (arr_index);
}

int	main(int argc, char **argv)
{
	int	*arr;

	if (argc == 1)
		ft_putstr_fd(argv[0], 1);
	else if (argc >= 2)
	{
		argc -= 1;
		argv += 1;
		arr = parse_arg_to_arr(&argc, argv);
		// LES INT OVERFLOWS AVEC ATOI <!>
		push_swap(argc, arr);
	}
	return (0);
}

// int	main(void)
//{
//	printf("%d", is_valid_str("+8669"));
//	return (0);
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/04/07 11:19:18 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	push_swap(int len, int *arr)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	if (is_sorted_descending(arr, len) == 1)
	{
		free(arr);
		return ;
	}
	a = init_stack('a', len, arr);
	b = init_stack('b', len, NULL);
	op = NULL;
	push_op(&op, "", '0');
	op_start = op;
	if (a.arr != NULL && b.arr != NULL && op != NULL)
	{
		sort(&a, &b, &op, op_start);
		merge_all_op(op_start->next);
		print_op(op_start->next);
		free_all(&a, &b, op_start);
		return ;
	}
	free_all(&a, &b, op_start);
	error_exit();
}

int	main(int argc, char **argv)
{
	int	*array;

	if (argc <= 1)
		return (EXIT_FAILURE);
	argc -= 1;
	argv += 1;
	array = arg_to_int_array(argc, argv);
	array = array_to_indexed_array(array, argc);
	push_swap(argc, array);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/09 17:48:59 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

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
	int	*arr;

	if (argc == 1)
		ft_putstr_fd(argv[0], STDOUT_FILENO);
	else if (argc >= 2)
	{
		argc -= 1;
		argv += 1;
		arr = arg_to_indexed_arr(&argc, argv);
		push_swap(argc, arr);
	}
	return (0);
}

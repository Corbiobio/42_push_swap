/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/06 11:57:18 by edarnand         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	*arr;

	if (argc == 1)
		ft_putstr_fd(argv[0], 1);
	else if (argc >= 2)
	{
		argc -= 1;
		argv += 1;
		arr = arg_to_indexed_arr(&argc, argv);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/07 11:49:07 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	push_swap(int len, int *arr)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	a = init_stack('a', len, arr);
	b = init_stack('b', len, NULL);
	op = NULL;
	push_op(&op, "", '0');
	op_start = op;
	if (a.arr != NULL && b.arr != NULL && op != NULL)
	{
		sort(&a, &b, &op);
		if (op->val == NULL)
		{
			free_all(&a, &b, op_start);
			error_exit();
		}
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
		ft_putstr_fd(argv[0], 1);
	else if (argc >= 2)
	{
		argc -= 1;
		argv += 1;
		arr = arg_to_indexed_arr(&argc, argv);
		push_swap(argc, arr);
	}
	return (0);
}
//#include <stdlib.h>

// int	main(void)
//{
//	printf("%d\n", atoi("-2147483671"));
//	printf("%d", ft_atoi("-2147483671"));
//	return (0);
//}

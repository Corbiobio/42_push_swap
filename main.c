/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/06 18:01:07 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void	merge_curr_op(t_op *op, char *new_val)
{
	if (op->count <= op->next->count)
	{
		op->val = new_val;
		op->next->count -= op->count;
		op->id = 0;
	}
	else
	{
		op->next->val = new_val;
		op->count -= op->next->count;
		op->next->id = 0;
	}
}

void	merge_all_op(t_op *start)
{
	while (start->next != NULL && start != NULL)
	{
		if (ft_strlen(start->val) == 1 && ft_strlen(start->next->val) == 1
			&& start->id != 0 && start->next->id != 0)
		{
			if (start->val[0] == 's' && start->next->val[0] == 's')
				merge_curr_op(start, "ss");
			else if (start->val[0] == 'r' && start->next->val[0] == 'r')
				merge_curr_op(start, "rr");
		}
		else if (ft_strlen(start->val) == 2 && ft_strlen(start->next->val) == 2
			&& start->id != 0 && start->next->id != 0)
		{
			if (start->val[0] == 'r' && start->next->val[0] == 'r')
				merge_curr_op(start, "rrr");
		}
		start = start->next;
	}
}

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
		// LES INT OVERFLOWS AVEC ATOI <!>
		push_swap(argc, arr);
	}
	return (0);
}

// int	main(void)
//{
//	printf("%d", ft_atoi("-2147483650"));
//	return (0);
//}

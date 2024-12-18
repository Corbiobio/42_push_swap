/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/18 14:46:13 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	get_best_to_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	lowest_num;
	int	lowest_move;
	int	move_to_top;
	int	move_to_sort;

	i = 0;
	lowest_num = -1;
	lowest_move = -1;
	while (i < b->len)
	{
		move_to_top = ft_abs(fastest_to_top(*b, b->arr[b->len - i - 1]));
		move_to_sort = ft_abs(fastest_to_sort(*a, b->arr[b->len - i - 1]));

		if (move_to_top + move_to_sort < lowest_move || lowest_move == -1)
		{
			lowest_num = b->arr[b->len - i - 1];
			lowest_move = move_to_top + move_to_sort;
		}
		i++;
	}
	return (lowest_num);
}

void	n_move_dir(t_stack st, int n, int dir, t_op **op)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (dir > 0)
			r(st, op);
		else
			rr(st, op);
		i++;
	}
}

void	sort(t_stack *a, t_stack *b, t_op **op, int num)
{
	int	move_top;
	int	move_sort;

	move_top = fastest_to_top(*b, num);
	move_sort = fastest_to_sort(*a, num);
	n_move_dir(*b, ft_abs(move_top), move_top, op);
	n_move_dir(*a, ft_abs(move_sort), move_sort, op);
	p(b, a, op);
}


int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	a = init_stack('a', argc - 1, argv);
	if (a.arr == NULL)
		return (error());
	b = init_stack('b', argc - 1, NULL);
	b.len = 0;
	if (b.arr == NULL)
		return (error());
	op = NULL;
	push_op(&op, NULL, '0');
	op_start = op;
	printf("------------------------------------------------------------------------------\n\n");

	average_sort(&a, &b, &op);
	print_stack(b);
	print_stack(a);

	int i = 0;
	while (b.len > 0 && i >= 0)
	{
		int best = get_best_to_sort(&a, &b);
		sort(&a, &b, &op, best);
		//print_stack(a);
		//print_stack(b);
		i++;
	}
	int data = fastest_to_top(a, 0);
	n_move_dir(a, ft_abs(data), data, &op);
	print_stack(a);




	print_op(op_start);
	free_op(op_start);
	free(a.arr);
	free(b.arr);
	return (0);
}

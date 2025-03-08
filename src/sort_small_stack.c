/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:46:51 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/08 17:56:33 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_stack *st, t_op **op)
{
	if (is_sorted_descending(st->arr, st->len) == 1 || st->len <= 1)
		return ;
	if (st->len == 2)
	{
		r(*st, op);
		return ;
	}
	if (st->arr[2] > st->arr[0] && st->arr[2] > st->arr[1])
		r(*st, op);
	else if (st->arr[1] > st->arr[0] && st->arr[1] > st->arr[2])
		rr(*st, op);
	if (is_sorted_descending(st->arr, st->len) == 1)
		return ;
	s(*st, op);
}

void	sort_stack_6(t_stack *a, t_stack *b, t_op **op)
{
	int	i;

	if (a->len >= 4)
	{
		i = 0;
		while (a->len >= 4)
		{
			if (a->arr[a->len - 1] <= a->len + b->len - 3)
				p(a, b, op);
			else
				r(*a, op);
		}
		sort_stack_3(b, op);
	}
	sort_stack_3(a, op);
	while (b->len > 0)
	{
		rr(*b, op);
		p(b, a, op);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:15:15 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/17 13:14:53 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_25_to_75_percent(t_stack *a, t_stack *b, t_op **op)
{
	int	len;
	int	max;
	int	min;
	int	mid;

	len = a->len;
	mid = len / 2;
	min = mid / 2;
	max = mid + min;
	while (len > 0)
	{
		if ((a->arr[a->len - 1] >= mid && a->arr[a->len - 1] <= max)
			|| (a->arr[a->len - 1] >= min && a->arr[a->len - 1] < mid))
		{
			p(a, b, op);
			if (b->arr[b->len - 1] >= min && b->arr[b->len - 1] < mid)
				r(*b, op);
		}
		else
			r(*a, op);
		len--;
	}
}

void	sort_0_to_100_percent(t_stack *a, t_stack *b, t_op **op)
{
	int	len;
	int	max;
	int	min;
	int	mid;

	len = a->len;
	max = a->len + b->len;
	mid = max / 2;
	min = 0;
	while (len > 2)
	{
		if ((a->arr[a->len - 1] >= mid && a->arr[a->len - 1] <= max)
			|| (a->arr[a->len - 1] >= min && a->arr[a->len - 1] < mid))
		{
			p(a, b, op);
			if (b->arr[b->len - 1] >= min && b->arr[b->len - 1] < mid)
				r(*b, op);
		}
		else
			r(*a, op);
		len--;
	}
}

void	average_sort(t_stack *a, t_stack *b, t_op **op)
{
	sort_25_to_75_percent(a, b, op);
	sort_0_to_100_percent(a, b, op);

	if (a->arr[0] < a->arr[1])
		r(*a, op);
	a->min = a->arr[1];
	a->max = a->arr[0];
}

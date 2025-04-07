/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quarter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:15:15 by edarnand          #+#    #+#             */
/*   Updated: 2025/04/07 11:45:34 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_25_to_75_percent(t_stack *a, t_stack *b, t_op **op)
{
	int	len;
	int	mid;

	len = a->len;
	mid = len / 2;
	while (len > 0)
	{
		if ((a->arr[a->len - 1] >= mid && a->arr[a->len - 1] <= a->max)
			|| (a->arr[a->len - 1] >= a->min && a->arr[a->len - 1] < mid))
		{
			p(a, b, op);
			if (b->arr[b->len - 1] >= a->min && b->arr[b->len - 1] < mid)
				r(*b, op);
		}
		else
			r(*a, op);
		len--;
	}
}

static void	sort_0_to_100_percent(t_stack *a, t_stack *b, t_op **op)
{
	int	mid;

	mid = a->max / 2;
	while (a->len > 2)
	{
		if ((a->arr[a->len - 1] >= mid && a->arr[a->len - 1] < a->max)
			|| (a->arr[a->len - 1] > a->min && a->arr[a->len - 1] < mid))
		{
			p(a, b, op);
			if (b->arr[b->len - 1] >= a->min && b->arr[b->len - 1] < mid)
				r(*b, op);
		}
		else
			r(*a, op);
	}
}

void	sort_quarter(t_stack *a, t_stack *b, t_op **op)
{
	a->min = a->len / 4;
	a->max = a->min * 3;
	if (a->min == 1)
		a->min = 2;
	sort_25_to_75_percent(a, b, op);
	a->min = 1;
	a->max = a->len + b->len;
	sort_0_to_100_percent(a, b, op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:31 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/01 16:24:27 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

void	sort_to_a(t_stack *a, t_stack *b, t_op **op, int num)
{
	int	move_top;
	int	move_sort;

	move_top = fastest_to_top(*b, num);
	move_sort = fastest_to_sort(*a, num);
	n_move_dir(*b, ft_abs(move_top), move_top, op);
	n_move_dir(*a, ft_abs(move_sort), move_sort, op);
	p(b, a, op);
}

void	sort(t_stack *a, t_stack *b, t_op **op)
{
	int	i;
	int	best;
	int	data;

	average_sort(a, b, op);
	i = 0;
	while (b->len > 0 && i >= 0)
	{
		best = get_best_to_sort(a, b);
		sort_to_a(a, b, op, best);
		i++;
	}
	data = fastest_to_top(*a, a->min);
	n_move_dir(*a, ft_abs(data), data, op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:24:00 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/20 18:37:00 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

int	error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
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

void	free_all(t_stack *a, t_stack *b, t_op *op)
{
	if (a->arr != NULL)
		free(a->arr);
	if (b->arr != NULL)
		free(b->arr);
	if (op != NULL)
		free_op(op);
}

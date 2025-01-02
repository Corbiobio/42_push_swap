/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:24:00 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/02 18:40:31 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	error(void)
{
	write(1, "Error\n", 6);
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
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

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		free(argv[i]);
		i++;
	}
	free(argv[i]);
	free(argv);
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

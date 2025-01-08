/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:24:00 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/07 13:08:21 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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

int	is_sorted_descending(int *arr, int len)
{
	int	i;

	i = 0;
	if (len < 0 || arr == NULL)
		return (0);
	if (len == 1)
		return (1);
	while (i < len - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

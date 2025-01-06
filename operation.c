/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:34:48 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/06 11:58:43 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	push_op(t_op **op, char *val, char id)
{
	t_op	*new;

	if (*op != NULL && (*op)->val == val && (*op)->id == id)
	{
		(*op)->count += 1;
		return ;
	}
	new = malloc(sizeof(t_op));
	if (new == NULL)
	{
		if (*op != NULL)
		{
			(*op)->count = -1;
			(*op)->val = NULL;
		}
		return ;
	}
	new->next = NULL;
	new->count = 1;
	new->val = val;
	new->id = id;
	if (*op != NULL)
		(*op)->next = new;
	*op = new;
}

void	free_op(t_op *start)
{
	t_op	*tmp;

	while (start != NULL)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
}

void	print_op(t_op *start)
{
	t_op	*copy;

	copy = start;
	while (copy != NULL)
	{
		if (copy->count == -1)
		{
			error();
			return ;
		}
		copy = copy->next;
	}
	while (start != NULL)
	{
		printf("%s%c\n", start->val, start->id);
		if (start->count > 1)
			start->count--;
		else
			start = start->next;
	}
}


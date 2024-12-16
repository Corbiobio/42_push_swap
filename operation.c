/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:34:48 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/16 12:40:07 by edarnand         ###   ########.fr       */
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
		return ;
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
	if (start->val == NULL)
		start = start->next;
	while (start != NULL)
	{
		printf("%s%c_", start->val, start->id);
		if (start->count > 1)
			start->count--;
		else
			start = start->next;
	}
}

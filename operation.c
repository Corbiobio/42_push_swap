/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:34:48 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/14 18:14:41 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	push_op(t_op **op, char *val, char id)
{
	t_op	*new;

	if (*op != NULL && (*op)->val == NULL)
		return ;
	if (*op != NULL && (*op)->val == val && (*op)->id == id)
	{
		(*op)->count += 1;
		return ;
	}
	new = malloc(sizeof(t_op));
	if (new == NULL)
	{
		if (*op != NULL)
			(*op)->val = NULL;
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
	while (start != NULL)
	{
		if (start->count >= 1)
		{
			ft_putstr_fd(start->val, STDOUT_FILENO);
			if (start->id != 0)
				ft_putchar_fd(start->id, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			start->count--;
		}
		else
			start = start->next;
	}
}

static void	merge_curr_op(t_op *op, char *new_val)
{
	if (op->count <= op->next->count)
	{
		op->val = new_val;
		op->next->count -= op->count;
		op->id = 0;
	}
	else
	{
		op->next->val = new_val;
		op->count -= op->next->count;
		op->next->id = 0;
	}
}

void	merge_all_op(t_op *start)
{
	while (start != NULL && start->next != NULL)
	{
		if (ft_strlen(start->val) == 1 && ft_strlen(start->next->val) == 1
			&& start->id != 0 && start->next->id != 0)
		{
			if (start->val[0] == 's' && start->next->val[0] == 's')
				merge_curr_op(start, "ss");
			else if (start->val[0] == 'r' && start->next->val[0] == 'r')
				merge_curr_op(start, "rr");
		}
		else if (ft_strlen(start->val) == 2 && ft_strlen(start->next->val) == 2
			&& start->id != 0 && start->next->id != 0)
		{
			if (start->val[0] == 'r' && start->next->val[0] == 'r')
				merge_curr_op(start, "rrr");
		}
		start = start->next;
	}
}

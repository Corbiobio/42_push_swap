/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/20 19:09:12 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	push_swap(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	a = init_stack('a', argc - 1, argv);
	b = init_stack('b', argc - 1, NULL);
	b.len = 0;
	op = NULL;
	push_op(&op, NULL, '0');
	op_start = op;
	if (a.arr != NULL && b.arr != NULL && op != NULL)
	{
		sort(&a, &b, &op);
		print_op(op_start->next);
	}
	else
		error();
	free_all(&a, &b, op_start);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd(argv[0], 1);
	else if (argc == 2)
		parsing(argv);//to do
	else
		push_swap(argc, argv);
	return (0);
}

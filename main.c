/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/16 12:37:23 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

t_stack	init_stack(char id, int len, char **argv)
{
	t_stack	st;
	int		i;

	st.id = id;
	st.len = len;
	st.arr = malloc(sizeof(int) * (len));
	if (id == 'a' && st.arr != NULL)
	{
		i = 0;
		while (len > 0)
		{
			st.arr[i] = ft_atoi(argv[len]);
			i++;
			len--;
		}
	}
	return (st);
}

void	print_stack(t_stack st)
{
	int	i;

	i = 0;
	while (i < st.len)
	{
		printf("%d ", st.arr[i]);
		i++;
	}
	printf("top\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	a = init_stack('a', argc - 1, argv);
	if (a.arr == NULL)
		return (error());
	b = init_stack('b', argc - 1, NULL);
	b.len = 0;
	if (b.arr == NULL)
		return (error());
	op = NULL;
	push_op(&op, NULL, '0');
	op_start = op;
	printf("------------------------------------------------------------------------------\n\n");



	print_stack(a);
	s(a, &op);
	s(a, &op);
	s(a, &op);
	s(a, &op);
	p(&a, &b, &op);
	print_stack(a);
	print_stack(b);

	print_op(op_start);
	free_op(op_start);
	free(a.arr);
	free(b.arr);
	return (0);
}

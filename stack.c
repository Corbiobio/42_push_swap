/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:11:05 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/06 16:58:43 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

t_stack	init_stack(char id, int len, int *arr)
{
	t_stack	st;

	st.id = id;
	if (id == 'a')
	{
		st.len = len;
		st.arr = arr;
	}
	if (id == 'b')
	{
		st.arr = malloc(sizeof(int) * (len));
		st.len = 0;
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

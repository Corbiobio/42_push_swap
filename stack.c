/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:11:05 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/17 10:14:08 by edarnand         ###   ########.fr       */
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

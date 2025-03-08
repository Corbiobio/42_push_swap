/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:11:05 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/14 18:16:03 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

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
		ft_putnbr_fd(st.arr[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("top\n\n", STDOUT_FILENO);
}

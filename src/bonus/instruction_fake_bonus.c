/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_fake.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:37:13 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/09 18:30:39 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_fake(t_stack st)
{
	int	tmp;
	int	i;

	if (st.len <= 1)
		return ;
	i = st.len - 1;
	tmp = st.arr[i];
	while (i > 0)
	{
		st.arr[i] = st.arr[i - 1];
		i--;
	}
	st.arr[0] = tmp;
}

void	rr_fake(t_stack st)
{
	int	tmp;
	int	i;

	if (st.len <= 1)
		return ;
	i = 0;
	tmp = st.arr[0];
	while (i < st.len - 1)
	{
		st.arr[i] = st.arr[i + 1];
		i++;
	}
	st.arr[st.len - 1] = tmp;
}

void	s_fake(t_stack st)
{
	int	tmp;

	if (st.len <= 1)
		return ;
	tmp = st.arr[st.len - 1];
	st.arr[st.len - 1] = st.arr[st.len - 2];
	st.arr[st.len - 2] = tmp;
}

void	p_fake(t_stack *from, t_stack *to)
{
	if (from->len == 0)
		return ;
	to->arr[to->len] = from->arr[from->len - 1];
	from->len -= 1;
	to->len += 1;
}

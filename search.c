/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:23:14 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/17 15:23:51 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fastest_way_from_top(t_stack st, int target)
{
	int	i;

	i = 0;
	while (i < st.len)
	{
		if (target == st.arr[st.len - i - 1])
			return (i);
		i++;
	}
	return (-1);
}

int	fastest_way_from_bot(t_stack st, int target)
{
	int	i;

	i = 0;
	while (i < st.len)
	{
		if (target == st.arr[i])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	fastest_way_to_top(t_stack st, int target)
{
	int	top;
	int	bot;

	top = fastest_way_from_top(st, target);
	bot = fastest_way_from_bot(st, target);
	if (top <= bot)
		return (top);
	else
		return (bot * -1);
}


int	fastest_index(t_stack st, int target, int flag)
{
	int	i;

	if (target > st.arr[0] && st.arr[0] == st.max)
		return (0);
	if (target < st.arr[st.len - 1] && st.arr[st.len - 1] == st.min)
		return (0);
	if (flag == 1)
	{
		i = 0;
		while (i < st.len - 1)
		{
			if (target < st.arr[i] && target > st.arr[i + 1])
				return (i + 1);
			i++;
		}
		return (-1);
	}
	i = st.len - 1;
	while (i > 0)
	{
		if (target > st.arr[i] && target < st.arr[i - 1])
			return (st.len - i);
		i--;
	}
	return (-1);
}

int	fastest_to_sort(t_stack st, int target)
{
	int		top;
	int		bot;

	top = fastest_index(st, target, 0);
	bot = fastest_index(st, target, 1);
	if (top <= bot)
		return (top);
	else
		return (bot * -1);
}

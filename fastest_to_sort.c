/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastest_to_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:06:45 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/18 12:37:12 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	index_from_top(t_stack st, int target)
{
	int	i;
	int	first;

	i = 0;
	while (i < st.len)
	{
		first = st.len - i - 1;
		if ((target > st.arr[first] && target < st.arr[first - 1])
			|| (target > st.arr[first] && st.arr[first] == st.max)
			|| (target < st.arr[first - 1] && st.arr[first - 1] == st.min))
			return (i + 1);
		i++;
	}
	return (-999);
}

static int	index_from_bot(t_stack st, int target)
{
	int	i;

	i = 0;
	while (i < st.len - 1)
	{
		if ((target < st.arr[i] && target > st.arr[i + 1])
			|| (target < st.arr[i] && st.arr[i] == st.min)
			|| (target > st.arr[i + 1] && st.arr[i + 1] == st.max))
			return (i + 1);
		i++;
	}
	return (-1);
}

int	fastest_to_sort(t_stack st, int target)
{
	int		top;
	int		bot;

	if ((target > st.arr[0] && st.arr[0] == st.max)
		|| (target < st.arr[st.len - 1] && st.arr[st.len - 1] == st.min)
		|| (target < st.arr[st.len - 1] && target > st.arr[0]))
		return (0);
	top = index_from_top(st, target);
	bot = index_from_bot(st, target);
	if (top <= bot)
		return (top);
	else
		return (bot * -1);
}

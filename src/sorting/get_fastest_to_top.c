/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fastest_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:23:14 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/14 18:17:16 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fastest_way_from_top(t_stack st, int target)
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

static int	fastest_way_from_bot(t_stack st, int target)
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

int	get_fastest_to_top(t_stack st, int target)
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

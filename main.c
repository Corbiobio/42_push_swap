/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/13 18:26:29 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	r(t_stack st)
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

void	rr(t_stack st)
{
	int	tmp;
	int	i;

	if (st.len <= 1)
		return ;
	i = 0;
	tmp = st.arr[0];
	while (i < st.len - 2)
	{
		st.arr[i] = st.arr[i + 1];
		i++;
	}
	st.arr[st.len - 1] = tmp;
}

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
	int		len;

	len = argc - 1;
	a = init_stack('a', len, argv);
	if (a.arr == NULL)
		return (error());
	b = init_stack('b', 0, NULL);
	if (b.arr == NULL)
		return (error());

	printf("\n");
	print_stack(a);


	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:18:07 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/14 13:12:45 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static int	is_correct_in(char in[])
{
	if (in == NULL || ft_strlen(in) < 2 || ft_strlen(in) > 3)
		return (0);
	if (in[0] == 's' && (in[1] == 's' || in[1] == 'a' || in[1] == 'b'))
		return (1);
	if (in[0] == 'p' && (in[1] == 'a' || in[1] == 'b'))
		return (1);
	if (ft_strlen(in) == 2 && in[0] == 'r')
	{
		if (in[1] == 'r' || in[1] == 'a' || in[1] == 'b')
			return (1);
	}
	else if (ft_strlen(in) == 3 && in[0] == 'r' && in[1] == 'r')
	{
		if (in[2] == 'r' || in[2] == 'a' || in[2] == 'b')
			return (1);
	}
	return (0);
}

static void	do_in(char in[], t_stack *a, t_stack *b)
{
	if (in[0] == 'p' && in[1] == 'a')
		p_fake(b, a);
	else if (in[0] == 'p' && in[1] == 'b')
		p_fake(a, b);
	if (in[0] == 's' && (in[1] == 'a' || in[1] == 's'))
		s_fake(*a);
	if (in[0] == 's' && (in[1] == 'b' || in[1] == 's'))
		s_fake(*b);
	if (ft_strlen(in) == 2 && in[0] == 'r')
	{
		if (in[1] == 'a' || in[1] == 'r')
			r_fake(*a);
		if (in[1] == 'b' || in[1] == 'r')
			r_fake(*b);
	}
	else if (ft_strlen(in) == 3 && in[0] == 'r' && in[1] == 'r')
	{
		if (in[2] == 'a' || in[2] == 'r')
			rr_fake(*a);
		if (in[2] == 'b' || in[2] == 'r')
			rr_fake(*b);
	}
}

#include <stdio.h>
static void	read_in(char in[])
{
	int	byte;

	byte = read(STDIN_FILENO, in, 4);
	if (byte <= 0)
		in[0] = '\0';
	else if (byte <= 4)
	{
		in[byte] = '\0';
		if (in[byte - 1] == '\n')
			in[byte - 1] = '\0';
	}
		
}

void	checker(t_stack a, t_stack b)
{
	char	in[5];
	int		is_correct;

	is_correct = 1;
	while (is_correct == 1)
	{
		read_in(in);
		is_correct = is_correct_in(in);
		if (is_correct == 1)
			do_in(in, &a, &b);
	}
	if (b.len >= 1 || is_sorted_descending(a.arr, a.len) == 0)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	free_all(&a, &b, NULL);
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		ft_putstr_fd(argv[0], 1);
	else if (argc >= 2)
	{
		argc -= 1;
		argv += 1;
		arr = NULL;
		arr = arg_to_indexed_arr(&argc, argv);
		a = init_stack('a', argc, arr);
		b = init_stack('b', argc, NULL);
		if (a.arr != NULL && b.arr != NULL)
			checker(a, b);
		else
		{
			free_all(&a, &b, NULL);
			error_exit();
		}
	}
	return (0);
}

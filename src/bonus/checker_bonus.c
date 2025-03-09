/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:18:07 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/09 12:22:05 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static int	is_correct_in(char *in)
{
	int	len;

	if (ft_strchr_index(in, '\n') >= 0)
		in[ft_strchr_index(in, '\n')] = '\0';
	len = ft_strlen(in);
	if (len < 2 || len > 3)
		return (0);
	if (len == 2)
	{
		if (in[0] == 's' && (in[1] == 's' || in[1] == 'a' || in[1] == 'b'))
			return (1);
		else if (in[0] == 'p' && (in[1] == 'a' || in[1] == 'b'))
			return (1);
		else if (in[0] == 'r' && (in[1] == 'r' || in[1] == 'a' || in[1] == 'b'))
			return (1);
	}
	else if (len == 3 && in[0] == 'r' && in[1] == 'r')
	{
		if (in[2] == 'r' || in[2] == 'a' || in[2] == 'b')
			return (1);
	}
	return (0);
}

static void	do_in(char *in, t_stack *a, t_stack *b)
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

void	checker(t_stack a, t_stack b)
{
	char	*in;
	int		is_correct;

	is_correct = 1;
	while (is_correct == 1)
	{
		in = get_next_line(STDIN_FILENO);
		if (in == NULL)
			error_exit();
		is_correct = is_correct_in(in);
		if (is_correct == 1)
			do_in(in, &a, &b);
		free(in);
	}
	if (b.len >= 1 || is_sorted_descending(a.arr, a.len) == 0)
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
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
		arr = arg_to_normalised_arr(&argc, argv);
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

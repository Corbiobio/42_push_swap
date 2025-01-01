/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:02 by edarnand          #+#    #+#             */
/*   Updated: 2025/01/01 19:01:20 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	push_swap(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_op	*op_start;
	t_op	*op;

	a = init_stack('a', argc - 1, argv);
	b = init_stack('b', argc - 1, NULL);
	op = NULL;
	push_op(&op, NULL, '0');
	op_start = op;
	if (a.arr != NULL && b.arr != NULL && op != NULL)
	{
		sort(&a, &b, &op);
		print_op(op_start->next);
	}
	else
		error();
	free_all(&a, &b, op_start);
}

int	is_valid_str(char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strlen(str) == 1)
	{
		if (ft_isdigit(*str) == 1)
			return (1);
		else
			return (0);
	}
	while (*str != '\0' && *(str + 1) != '\0')
	{
		if (*str != '-' && *str != '+' && ft_isdigit(*str) == 0)
			return (0);
		else if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)) == 0)
			return (0);
		else if (ft_isdigit(*str) == 1 && ft_isdigit(*(str + 1)) == 0)
			return (0);
		str++;
	}
	return (1);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		free(argv[i]);
		i++;
	}
	free(argv[i]);
	free(argv);
}

char	**parse_params(int *argc, char **argv)
{
	int	i;

	if (*(argc) == 1)
	{
		argv = ft_split(argv[0], ' ');
		if (argv == NULL)
			error_exit();
		*(argc) = 0;
		while (argv[*(argc)] != 0)
			*(argc) += 1;
	}
	i = 0;
	while (i < *(argc))
	{
		if (is_valid_str(argv[i]) == 0)
		{
			if (*(argc) == 1)
				free_argv(argv);
			error_exit();
		}
		i++;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	char	**test;

	test = NULL;
	if (argc == 1)
		ft_putstr_fd(argv[0], 1);
	else if (argc >= 2)
	{
		argc -= 1;
		argv = parse_params(&argc, argv + 1);
		push_swap(argc, argv);
		if (argc == 2)
			free_argv(argv);
	}
	return (0);
}

// int	main(void)
//{
//	printf("%d", is_valid_str("+8669"));
//	return (0);
//}

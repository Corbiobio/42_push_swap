/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:08:06 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/08 15:36:13 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	is_valid_str(char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strlen(str) == 1)
	{
		if (ft_isdigit(*str) == 1)
			return (1);
		return (0);
	}
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

char	**parse_arg(int argc, char **argv, int *to_free)
{
	int	i;

	if (argc == 1)
	{
		argv = ft_split(argv[0], ' ');
		if (argv == NULL)
			error_exit();
		*to_free = 1;
		argc = 0;
		while (argv[argc] != 0)
			argc += 1;
	}
	i = 0;
	while (i < argc)
	{
		if (is_valid_str(argv[i]) == 0)
		{
			if (*to_free == 1)
				free_argv(argv);
			error_exit();
		}
		i++;
	}
	return (argv);
}

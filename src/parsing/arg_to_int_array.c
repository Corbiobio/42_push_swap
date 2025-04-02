/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_int_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:51:45 by edarnand          #+#    #+#             */
/*   Updated: 2025/04/02 13:47:03 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	free_arr_and_exeit_error(int *arr)
{
	free(arr);
	error_exit();
}

int	*arg_to_int_array(int argc, char **argv)
{
	int	i;
	int	j;
	int	*array;

	array = malloc(sizeof(int) * argc);
	if (array == NULL)
		error_exit();
	i = argc - 1;
	while (i >= 0)
	{
		if (ft_atoi_protected(argv[argc - 1 - i], array + i) == 0)
			free_arr_and_exeit_error(array);
		j = i + 1;
		while (j < argc)
		{
			if (array[j] == array[i])
				free_arr_and_exeit_error(array);
			j++;
		}
		i--;
	}
	return (array);
}

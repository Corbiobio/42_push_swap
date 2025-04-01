/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_int_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:18:16 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/26 16:37:07 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
		if (ft_atoi_protected(argv[i], array + i) == 0)
			free_arr_and_exeit_error(array);
		j = i;
		while (++j < argc)
		{
			if (array[j] == array[i])
				free_arr_and_exeit_error(array);
		}
		i--;
	}
	return (array);
}

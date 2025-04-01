/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_protected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:39 by edarnand          #+#    #+#             */
/*   Updated: 2025/03/27 11:33:50 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clean(char **str)
{
	int	is_negative;

	is_negative = 0;
	if (*str[0] == '-' || *str[0] == '+')
	{
		if (*str[0] == '-')
			is_negative = 1;
		*str += 1;
	}
	return (is_negative);
}

static int	do_calcul(int is_negative, char *str, int *i, int *int_pt)
{
	while (ft_isdigit(str[*i]) == 1)
	{
		if (is_negative)
		{
			if (*int_pt * 10 - (str[*i] - '0') > *int_pt)
				return (0);
			*int_pt = *int_pt * 10 - (str[*i] - '0');
		}
		else
		{
			if (*int_pt * 10 + (str[*i] - '0') < *int_pt)
				return (0);
			*int_pt = *int_pt * 10 + (str[*i] - '0');
		}
		(*i)++;
	}
	return (1);
}

int	ft_atoi_protected(const char *str, int *int_pt)
{
	int	i;
	int	is_negative;

	if (str == NULL)
		return (0);
	i = 0;
	*int_pt = 0;
	is_negative = clean((char **)&str);
	if (do_calcul(is_negative, (char *)str, &i, int_pt) == 0
		|| str[i] != '\0' || i == 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:15:08 by edarnand          #+#    #+#             */
/*   Updated: 2024/11/12 18:47:37 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(int n, int fd)
{
	char	c;

	c = '0' + n;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		i *= -1;
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	putnbr(i % 10, fd);
}

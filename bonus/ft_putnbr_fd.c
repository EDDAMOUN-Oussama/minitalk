/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:39:11 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/23 16:39:26 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n <= -10)
			ft_putnbr_fd(-(n / 10), fd);
		c = -(n % 10) + '0';
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + '0';
	}
	write(fd, &c, 1);
}

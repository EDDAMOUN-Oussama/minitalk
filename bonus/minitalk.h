/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:54:24 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/26 10:54:25 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		len;
	int		i;
	int		j;
	int		pid_c;
	int		bit;
	int		c;
	char	*str;
}			t_data;

int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_strlen(char *str);
#endif
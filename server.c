/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:38:15 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/23 21:44:28 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_action(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static int			pid_c;
	int			bit;

	if (pid_c != info->si_pid)
	{
		i = 0;
		c = 0;
		pid_c = info->si_pid;
	}
	if (sig == SIGUSR1)
		bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	c = c * 2 + bit;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("please only ./server\n", 2);
		exit(1);
	}
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
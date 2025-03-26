/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:38:15 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/26 10:55:59 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_inisial(t_data *v, int c)
{
	if (c == 2)
	{
		ft_putstr_fd(v->str, 1);
		kill(v->pid_c, SIGUSR2);
	}
	free(v->str);
	v->str = NULL;
	v->c = 0;
	v->j = 0;
	v->len = 0;
	v->i = 0;
	if (c == 1)
	{
		ft_putstr_fd("Error: malloc fatal\n", 2);
		exit(1);
	}
}

void	ft_to_str(t_data *v)
{
	if (v->i == 32 && !v->c)
	{
		v->i = 0;
		if (v->len == 0)
			return ;
		v->str = malloc(v->len + 1);
		if (!v->str)
			ft_inisial(v, 1);
		v->c = 1;
		v->len = 0;
	}
	else if (v->i == 8 && v->c)
	{
		v->str[(v->j)++] = (unsigned char)v->len;
		if (v->str[v->j - 1] == '\0')
			ft_inisial(v, 2);
		v->len = 0;
		v->i = 0;
	}
}

void	ft_action(int sig, siginfo_t *info, void *context)
{
	static t_data	v;

	(void)context;
	if (v.pid_c != info->si_pid)
	{
		v.pid_c = info->si_pid;
		ft_inisial(&v, 0);
	}
	if (sig == SIGUSR1)
		v.bit = 0;
	if (sig == SIGUSR2)
		v.bit = 1;
	v.len = v.len * 2 + v.bit;
	(v.i)++;
	ft_to_str(&v);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

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
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:14:30 by oeddamou          #+#    #+#             */
/*   Updated: 2025/03/26 09:47:11 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void    ft_send_char(pid_t pid, unsigned char c)
{
    char     byte[8];
    int     i;

    i = 7;
    while (i >= 0)
    {
        byte[i] = c % 2;
        c /= 2;
        i--;
    }
    while (++i < 8)
    {
        if (byte[i] == 0)
            kill(pid, SIGUSR1);
        if (byte[i] == 1)
            kill(pid, SIGUSR2);
        usleep(300);
    }
}

void    ft_send_int(pid_t pid, int c)
{
    int     byte[32];
    int     i;

    i = 31;
    while (i >= 0)
    {
        byte[i] = c % 2;
        c /= 2;
        i--;
    }
    while (++i < 32)
    {
        if (byte[i] == 0)
            kill(pid, SIGUSR1);
        if (byte[i] == 1)
            kill(pid, SIGUSR2);
        usleep(300);
    }
}

void    ft_send(pid_t pid, char *str)
{
    int     i;
    int len;

    i = 0;
    len = ft_strlen(str);
    ft_send_int(pid, len);
    while (str[i])
    {
        ft_send_char(pid, str[i]);
        i++;
    }
    ft_send_char(pid, 0);
}

int main(int ac, char **av)
{
    int pid_s;
    
    if (ac != 3)
    {
        ft_putstr_fd("the correct forma:\n./client <PID:int> <str:string>", 2);
        exit(1);
    }
    pid_s = ft_atoi(av[1]);
    if (pid_s < 0 || kill(pid_s, 0) < 0)
    {
        ft_putstr_fd("error: PID not correct\n", 2);
        exit(1);
    }
    ft_send(pid_s, av[2]);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:23:53 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/19 09:34:05 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(char c, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else if (c)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
		exit(1);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		ft_send(av[2][i], pid);
		i++;
	}
}

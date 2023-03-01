/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:27 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/19 09:34:28 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_rsv(int sg)
{
	static char	c;
	static int	i;

	c |= (sg == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		ft_putchar(c);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, &ft_rsv);
	signal(SIGUSR2, &ft_rsv);
	while (1)
		pause();
}

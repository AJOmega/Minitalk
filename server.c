/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:52:57 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/07/30 06:19:19 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_writemnsg(int signal)
{
	static int	binary[] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int	i = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
		c += binary[i++];
	if (i >= 8)
	{
		if (c != 0)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	//ft_printf("PID: %u\n", getpid());
	write(1, "PID: ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	//write(1,"PID: %u\n", 9);
	signal(SIGUSR1, ft_writemnsg);
	signal(SIGUSR2, ft_writemnsg);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:19:57 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/07/30 06:16:04 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	ft_isnull(int pid, char c)
{
	int	shift;

	shift = 8;
	while (--shift >= 0)
	{
		if ((c >> shift & 1) == 0)
		{
			kill(pid, SIGUSR1);
			usleep(200);
		}
		else if ((c >> shift & 1) == 1)
		{
			kill(pid, SIGUSR2);
			usleep(200);
		}
	}
}

static void	ft_sendmnsg(int pid, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_isnull(pid, str[i]);
	ft_isnull(pid, 0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		//ft_printf("Number of arguments needs to be 2!\n");
		write(1, "Number of arguments needs to be 2!\n", 36);
		return (0);
	}
	pid = ft_atoi(av[1]);
	ft_sendmnsg(pid, av[2]);
}

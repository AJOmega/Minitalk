/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 05:20:15 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/07/30 06:14:00 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_number(int number, int fd)
{
	if (number > 9)
		print_number(number / 10, fd);
	number = (number % 10) + '0';
	write(fd, &number, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!fd && fd > 0)
		return ;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	print_number(n, fd);
}

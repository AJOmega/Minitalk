/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:48:49 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/07/30 06:14:35 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// Signal.h for functions to send signals
// Sys/types to represent process IDs

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

int	ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);\
void	print_number(int number, int fd);
void	ft_putnbr_fd(int n, int fd);


#endif
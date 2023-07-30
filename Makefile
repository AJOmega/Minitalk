# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 04:22:04 by jabreu-d          #+#    #+#              #
#    Updated: 2023/07/30 06:03:45 by jabreu-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c minitalk_utils.c

OBJS	= $(SRCS.c=.o)

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

CC = cc

all:
	@$(CC) $(CFLAGS) server.c minitalk_utils.c -o server
	@$(CC) $(CFLAGS) client.c minitalk_utils.c -o client

clean:
	@rm -rf server
	@rm -rf client

fclean: clean

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 21:11:08 by hchadili          #+#    #+#              #
#    Updated: 2024/03/08 23:06:59 by hchadili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SEV = server
SEV_B = server_bonus

CLI = client
CLI_B = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_C = Mandatory/client.c Mandatory/ft_itoa.c Mandatory/ft_atoi.c

SRC_S = Mandatory/server.c Mandatory/ft_atoi.c Mandatory/ft_itoa.c

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

all: $(CLI) $(SEV)
	
$(CLI): $(OBJS_C)
	$(CC) $(OBJS_C) -o $(CLI)
	
$(SEV): $(OBJS_S)
	$(CC) $(OBJS_S) -o $(SEV)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@
		
bonus: $(SEV_B) $(CLI_B)

clean:
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)
fclean: clean
	$(RM) $(SEV)
	$(RM) $(CLI)
	
re: fclean all

.PHONY: all clean fclean re
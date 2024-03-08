# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 21:11:08 by hchadili          #+#    #+#              #
#    Updated: 2024/03/08 23:58:49 by hchadili         ###   ########.fr        #
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

SRC_CB = Bonus/client.c Bonus/ft_itoa.c Bonus/ft_atoi.c Bonus/put_char.c
SRC_SB = Bonus/server.c Bonus/ft_atoi.c Bonus/ft_itoa.c Bonus/put_char.c

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

#bonus
OBJS_CB = $(SRC_CB:.c=.o)
OBJS_SB = $(SRC_SB:.c=.o)

all: $(CLI) $(SEV)

bonus: $(SEV_B) $(CLI_B)
	
$(CLI): $(OBJS_C)
	$(CC) $(OBJS_C) -o $(CLI)
	
$(SEV): $(OBJS_S)
	$(CC) $(OBJS_S) -o $(SEV)

#bonus
$(CLI_B): $(OBJS_CB)
	$(CC) $(OBJS_CB) -o $(CLI_B)
	
$(SEV_B): $(OBJS_SB)
	$(CC) $(OBJS_SB) -o $(SEV_B)

Mandatory/%.o : Mandatory/%.c Mandatory/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@
	
Bonus/%.o : Bonus/%.c Bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)
	$(RM) $(OBJS_SB)
	$(RM) $(OBJS_CB)
fclean: clean
	$(RM) $(SEV)
	$(RM) $(CLI)
	$(RM) $(SEV_B)
	$(RM) $(CLI_B)
	
re: fclean all

.PHONY: all clean fclean re
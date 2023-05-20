# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:03:03 by abazerou          #+#    #+#              #
#    Updated: 2023/05/20 14:42:11 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = push_swap.c utils.c sort3.c

red			=	`tput setaf 1`
green		=	`   tput setaf 2`

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo " $(green)SUCCESS ==>$(white) push_swap $(green)is ready$(white)."
	@echo " _______         _______             _______         _______ _______ "
	@echo " (  ____ |\     /(  ____ |\     /|   (  ____ |\     /(  ___  (  ____ ) "
	@echo " | (    )| )   ( | (    \| )   ( |   | (    \| )   ( | (   ) | (    )| "
	@echo " | (____)| |   | | (_____| (___) |   | (_____| | _ | | (___) | (____)| "
	@echo " |  _____| |   | (_____  |  ___  |   (_____  | |( )| |  ___  |  _____) "
	@echo " | (     | |   | |     ) | (   ) |         ) | || || | (   ) | (       "
	@echo " | )     | (___) /\____) | )   ( |   /\____) | () () | )   ( | )       "
	@echo " |/      (_______\_______|/     \____\_______(_______|/     \|/        "
	@echo "                                                                       "

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@echo " $(green)OBJ & EXEC$(white) push_swap $(green)removed$(white)."

re: fclean all

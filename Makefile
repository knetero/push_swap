# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:03:03 by abazerou          #+#    #+#              #
#    Updated: 2023/05/27 13:35:47 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = push_swap.c utils.c sort.c instructions.c f_helpers.c parsing.c 2_instructions.c 2_utils.c 3_utils.c 2_sort.c big_sort.c

red    =   `tput setaf 1`
green  =   `tput setaf 2`
yellow =   `tput setaf 3`


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "                                                                                "
	@echo "$(green)✓ ██░░[SUCCESS:$(green)PUSH_SWAP $(green)IS READY]░░██$(white)"
	@echo "                                                                                "
	@echo "$(green)██████╗░██╗░░░██╗░██████╗██╗░░██╗░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░ "
	@echo "$(green)██╔══██╗██║░░░██║██╔════╝██║░░██║██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗ "
	@echo "$(green)██████╔╝██║░░░██║╚█████╗░███████║╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝ "
	@echo "$(green)██╔═══╝░██║░░░██║░╚═══██╗██╔══██║░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░ "
	@echo "$(green)██║░░░░░╚██████╔╝██████╔╝██║░░██║██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░ "
	@echo "$(green)╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░ "
	@echo "                                                                                "

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<


clean:
	@rm -f $(OBJS)
	@echo " $(red)✗ [OBJ]$(red) push_swap $(red)removed$(white)."

fclean: clean
	@rm -f $(NAME)
	@echo " $(red)✗ [OBJ & EXEC]$(green) push_swap $(red)removed$(green)."

re: fclean all
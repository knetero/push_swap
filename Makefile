# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:03:03 by abazerou          #+#    #+#              #
#    Updated: 2023/05/31 17:46:24 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = push_swap.c parsing.c parsing2.c\
				sort1.c sort2.c big_sort.c\
				first_instructions.c second_instructions.c\
				split_args.c function_helpers.c function_helpers2.c function_helpers3.c get_positions.c\
		
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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:03:03 by abazerou          #+#    #+#              #
#    Updated: 2023/05/30 20:18:59 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
NAME = push_swap
SRCS = push_swap.c parsing.c parsing2.c\
				sort1.c sort2.c big_sort.c\
				f1_instructions.c f2_instructions.c\
				1_utils.c 2_utils.c 3_utils.c 4_utils.c f_helpers.c\
		
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
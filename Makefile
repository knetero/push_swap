# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:03:03 by abazerou          #+#    #+#              #
#    Updated: 2023/06/05 22:21:26 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
NAMEB = checker
SRCS = push_swap.c parsing.c parsing2.c\
				sort1.c sort2.c big_sort.c\
				first_instructions.c second_instructions.c\
				split_args.c function_helpers.c function_helpers2.c function_helpers3.c get_positions.c\


SRCSB =  checker.c parsing_bonus.c parsing2_bonus.c get_next_line.c get_next_line_utils.c \
				first_instructions_bonus.c second_instructions_bonus.c\
				split_args_bonus.c function_helpers_bonus.c function_helpers2_bonus.c function_helpers3_bonus.c list_creation.c\

HEADER = push_swap.h

red    =   `tput setaf 1`
green  =   `tput setaf 2`
yellow =   `tput setaf 3`


OBJS = $(SRCS:.c=.o)
OBJB = $(SRCSB:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "                                                                                "
	@echo "$(green)✓ SUCCESS: ██░░[$(green)PUSH_SWAP $(green)IS READY]░░██$(white)"
	@echo "                                                                                "
	@echo "$(green)██████╗░██╗░░░██╗░██████╗██╗░░██╗░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░ "
	@echo "$(green)██╔══██╗██║░░░██║██╔════╝██║░░██║██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗ "
	@echo "$(green)██████╔╝██║░░░██║╚█████╗░███████║╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝ "
	@echo "$(green)██╔═══╝░██║░░░██║░╚═══██╗██╔══██║░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░ "
	@echo "$(green)██║░░░░░╚██████╔╝██████╔╝██║░░██║██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░ "
	@echo "$(green)╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░ "
	@echo "                                                                                "



bonus: $(NAMEB)

$(NAMEB): $(OBJB) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB)
	@echo "$(green)✓ SUCCESS: ██░░[BONUS IS READY]░░██$(white)"


%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $<


clean:
	@rm -f $(OBJS)
	@rm -f $(OBJB)
	@echo " $(red)✗ [OBJ]$(red)$(red) REMOVED$(white)."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAMEB)
	@echo " $(red)✗ [OBJ & EXEC]$(red) REMOVED."

re: fclean all
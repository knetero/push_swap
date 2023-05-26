# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 17:03:03 by abazerou          #+#    #+#              #
#    Updated: 2023/05/26 16:32:54 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = push_swap.c utils.c sort.c instructions.c f_helpers.c parsing.c 2_instructions.c 2_utils.c 3_utils.c

red    =   `tput setaf 1`
green  =   `tput setaf 2`
yellow =   `tput setaf 3`
white  =   `tput sgr0`

ANIMATION = . . . .

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
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



# Define the animation frames
ANIMATION = ' ✓'

%.o: %.c push_swap.h
	@printf "$(green)✓ Compiling $< $(green)"
	@for i in $(ANIMATION); do \
	    printf "\b$$i"; \
	    sleep 0.009; \
	done
	@printf "\b \b" # Delete the last animation frame
	@printf "\033[K" # Clear the line
	@printf "\r" # Move the cursor to the beginning of the line
	@$(CC) $(CFLAGS) -c $<


clean:
	@rm -f $(OBJS)
	@echo " $(red)✗ [OBJ]$(red) push_swap $(red)removed$(white)."

fclean: clean
	@rm -f $(NAME)
	@echo " $(red)✗ [OBJ & EXEC]$(green) push_swap $(red)removed$(white)."

re: fclean all

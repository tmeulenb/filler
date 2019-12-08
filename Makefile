#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmeulenb <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/06 20:59:41 by tmeulenb      #+#    #+#                  #
#    Updated: 2019/06/04 17:52:15 by tmeulenb      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = tmeulenb.filler

SRCS = srcs/main.c srcs/free.c srcs/save_map.c srcs/place_piece.c \
	   srcs/save_piece.c srcs/save_cut_piece.c srcs/heat_map.c \
	   srcs/save_cut_piece_help.c srcs/queue.c
OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra -o
GCC = gcc
GNL = ./gnl/get_next_line.c
LIBS = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft/ > /dev/null
	@$(GCC) -g $(SRCS) $(GNL) $(FLAGS) $(NAME) $(LIBS) > /dev/null
	@echo "\033[32mFILLER READY\033[0m"

clean:
	@rm -rf $(OBJ) > /dev/null
	@make clean -C libft/ > /dev/null
	@echo "\033[33mOBJ FILES REMOVED\033[0m"

fclean: clean
	@rm -rf filler > /dev/null 
	@make fclean -C libft/ > /dev/null
	@echo "\033[31mBINARIES REMOVED\033[0m"

re: fclean all

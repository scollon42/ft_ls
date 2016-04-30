# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollon <scollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 10:19:30 by scollon           #+#    #+#              #
#    Updated: 2016/04/30 09:09:42 by scollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH 		= ./src/
OBJ_PATH		= ./obj/
INC_PATH		= ./include/
LIB_PATH 		= ./lib/
INC_PATH 		= ./include/ 	\
				$(LIB_PATH)libft/include/ \
				$(LIB_PATH)libftprintf/include/

NAME 			= ft_ls
CC 				= gcc
CFGLAGS 		= -Werror -Wextra -Wall

SRC_NAME		= main.c read_arg.c parse_arg.c sort.c core.c  \
				  sort_condition.c print_ls.c utils.c error.c

OBJ_NAME 		= $(SRC_NAME:.c=.o)

LIB_NAME = libft libftprintf

SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ 			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC				= $(addprefix -I,$(INC_PATH))
INC_LIBFT 		= $(addprefix -I,$(INC_LIBFT_PATH))
LIB				= $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	make -C $(LIB_PATH)libftprintf -j
	$(CC) $(CFLGS) $(LIB) -lft -lftprintf $(INC) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -o $@ -c $<

.PHONY: clean fclean re check fclean_libft clean_libft

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

clean_libft:
	make -C libft clean

fclean: clean
	make -C $(LIB_PATH)libft fclean
	make -C $(LIB_PATH)libftprintf fclean
	rm -f $(NAME)

re: fclean all

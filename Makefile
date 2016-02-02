# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollon <scollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 10:19:30 by scollon           #+#    #+#              #
#*   Updated: 2016/02/01 18:49:01 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRC_PATH 		= ./src/
OBJ_PATH		= ./obj/
INC_PATH		= ./include/
LIB_PATH		= ./libft/
INC_LIBFT_PATH		= $(LIB_PATH)includes/

NAME 			= ft_ls
CC 			= gcc
CFGLAGS 		= -Werror -Wextra -Wall

SRC_NAME 		= main.c read_arg.c parse_arg.c error.c
OBJ_NAME 		= $(SRC_NAME:.c=.o)

LIB 			= $(LIB_PATH)libft.a

SRC			= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ 			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			= $(addprefix -I,$(INC_PATH))
INC_LIBFT 		= $(addprefix -I,$(INC_LIBFT_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(MLX)  $(INC) $(INC_LIBFT) $(OBJ) $(LIB) -o $(NAME)

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
	rm -f $(NAME)

fclean_libft:
	make -C libft fclean

re: fclean all

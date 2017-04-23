# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/02 09:09:23 by tprysiaz          #+#    #+#              #
#    Updated: 2017/04/02 09:10:58 by tprysiaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Werror -Wextra -O3
MLX_FLAGS = -lmlx -framework OpenGl -framework AppKit
SRC = fractol_main.c ft_hooks.c ft_image_color.c ft_main_algorithms.c ft_tools.c \
		ft_evaluation_of_coords.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)
$(NAME): $(OBJ)
	clang $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC)
	rm -r $(OBJ)

%.o: %.c
	clang -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all

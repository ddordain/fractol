# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 17:31:17 by ddordain          #+#    #+#              #
#    Updated: 2022/02/22 14:56:55 by ddordain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

NAME			=	fractol

SRC				=	./src
SRCS			=	main.c \
					algorithm.c \
					draw.c \
					init.c \
					hook.c \
					utils.c
					

OBJ				=	./objects
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

INC_DIR			=	./include

SYS_CAL			=	-l Xext -l X11 -l m -l bsd

MLX_DIR			=	./minilibx-linux

MLX_LIB			=	mlx_Linux

MLX_CAL			=	-L $(MLX_DIR) -l $(MLX_LIB)

FT_DIR			=	./libft

FT_LIB			=	ft

FT_CAL			=	-L $(FT_DIR) -l $(FT_LIB)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -O3 -g

LIBS			=	$(MLX_CAL) $(FT_CAL) $(SYS_CAL)

INCS			=	-I $(MLX_DIR) -I $(INC_DIR) -I $(FT_DIR)/includes

SAN				=	-g3 -fsanitize=address

RM				=	rm -rf

DIR_GUARD		=	mkdir -p $(@D)

$(OBJ)/%.o:	$(SRC)/%.c
				$(DIR_GUARD)
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				make all -C $(FT_DIR)
				make all -C $(MLX_DIR)
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

all:			$(NAME)

bonus:			$(NAME)

fsan:			$(OBJS)
				make all -C $(FT_DIR)
				make all -C $(MLX_DIR)
				$(CC) $(SAN) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

clean:
				$(RM) $(OBJ)
				make $@ -C $(MLX_DIR)
				make $@ -C $(FT_DIR)

fclean: 		clean
				$(RM) $(NAME)
				make $@ -C $(FT_DIR)

re:				fclean all

norm:
	norminette $(SRC) $(FT_DIR) $(INC_DIR)

.PHONY:			all bonus fsan clean fclean re

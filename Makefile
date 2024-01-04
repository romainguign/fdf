# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:50:47 by roguigna          #+#    #+#              #
#    Updated: 2024/01/04 11:31:21 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

LIBMLX_DIR 		= MacroLibX

CC				= clang

FLAGS 			= -Wall -Wextra - Werror

INCLUDE			= -I MacroLibX/includes -I libft/includes -I includes

MLX_FLAGS		= -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR)

LIB				= -L libft -lft -L MacroLibX

OBJF			=	.cache_exist

##############################  SOURCES  #####################################

SRC_DIR			= sources

OBJ_DIR			= object

SRC_FILES		= $(SRC_DIR)/*

OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:
	$(CC) -g $(SRC_FILES) $(LIB) $(MLX_FLAGS) $(INCLUDE) -o $(NAME)
	./fdf ./maps/42.fdf

${OBJ_DIR}%.o: ${SRC_DIR}%.c | ${OBJF}
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJF):
	@mkdir -p ${OBJ_DIR}
	
re:
	clang -g ./sources/* -L libft -lft -L MacroLibX -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR) -I MacroLibX/includes -I libft/includes -I includes
	./a.out ./maps/test.fdf
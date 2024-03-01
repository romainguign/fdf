# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:50:47 by roguigna          #+#    #+#              #
#    Updated: 2024/03/01 15:05:42 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

NAME_BONUS		= fdf_bonus

LIBMLX_DIR 		= MacroLibX

MacroLibX		= $(LIBMLX_DIR)/libmlx.so

LIBFT			= libft/libft

CC				= cc

FLAGS 			= -Wall -Wextra - Werror

INCLUDE			= -I MacroLibX/includes -I libft/includes -I includes

INCLUDE_BONUS	= -I MacroLibX/includes -I libft/includes -I includes

MLX_FLAGS		= -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR) -O3

LIB				= -L libft -lft -L MacroLibX

##############################  COLORS  ###################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[3;92m
YELLOW = \033[0;93m
BLUE = \033[3;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

##############################  SOURCES  #####################################


SRC_DIR			= sources

SRC_BONUS_DIR	= sources_bonus

OBJ_DIR			= object

OBJ_BONUS_DIR	= object_bonus

SRC_FILES		= aff_window.c draw_full_map.c draw_line_left.c draw_line_right.c \
				  draw.c events.c fdf.c free_map.c get_color.c init.c read_value.c \
				  read.c two_dimension.c update_values.c utils.c tester.c 

SRC_BONUS_FILES	= aff_window_bonus.c draw_full_map_bonus.c draw_line_left_bonus.c draw_line_right_bonus.c \
				  draw_bonus.c events_bonus.c fdf_bonus.c free_map_bonus.c get_color_bonus.c init_bonus.c read_value_bonus.c \
				  read_bonus.c two_dimension_bonus.c update_values_bonus.c utils_bonus.c modif_map_bonus.c tester.c
				
###########   supprimertester.c

OBJ             = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

OBJ_BONUS		= $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_FILES:.c=.o))

all: $(NAME) ascii

$(NAME): $(MacroLibX) $(LIBFT) $(OBJ) 
	$(CC) -g $(OBJ) $(LIB) $(MLX_FLAGS) $(INCLUDE) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MacroLibX):
	@make --quiet -C $(LIBMLX_DIR) -j

$(OBJ_DIR) $(OBJ_BONUS_DIR):
	@mkdir -p $@

$(LIBFT):
	@make --quiet -C libft 

bonus: $(NAME_BONUS) ascii

$(NAME_BONUS): $(MacroLibX) $(LIBFT) $(OBJ_BONUS) 
	$(CC) -g3 $(OBJ_BONUS) $(LIB) $(MLX_FLAGS) $(INCLUDE_BONUS) -o $(NAME_BONUS) 

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@

ascii:
	@echo "${CYAN}"
	@echo "\t\t_______________ ______       _________             ________              "
	@echo "\t\t___  ____/___(_)___  /       ______  /_____        ___  __/_____ ________"
	@echo "\t\t__  /_    __  / __  /        _  __  / _  _ \       __  /_  _  _ \__  ___/"
	@echo "\t\t_  __/    _  /  _  /         / /_/ /  /  __/       _  __/  /  __/_  /    "
	@echo "\t\t/_/       /_/   /_/          \__,_/   \___/        /_/     \___/ /_/     "
	@echo "\t\t                                                                        "
	@echo "${DEF_COLOR}"

clean:
	@make --quiet clean -C libft
	@make --quiet clean -C MacroLibX
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@echo "${GRAY}Fdf object files cleaned! ${DEF_COLOR}"

fclean: clean
	@make --quiet fclean -C libft
	@make --quiet fclean -C MacroLibX
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "${YELLOW}Fdf executable files cleaned! ${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re

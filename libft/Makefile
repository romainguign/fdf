# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 18:13:11 by roguigna          #+#    #+#              #
#    Updated: 2024/03/01 12:49:22 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################  VARIABLES  ###################################

NAME            = libft.a

FT_PRINTF       = ft_printf

libftprintf     = libftprintf.a

GNL             = get_next_line

OBJ_DIR         = obj

SRC_FILES       = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				  ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c \
				  ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
				  ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_itoa.c \
				  ft_strmapi.c ft_striteri.c ft_lstnew.c ft_lstadd_front.c \
				  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

CC              = clang

CFLAGS          = -Wall -Wextra -Werror

INCLUDE         = -Iincludes

##############################  COLORS  ###################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

##############################   RULES   ######################################

all: $(NAME)

$(NAME): $(OBJ)
	@make --quiet -C $(FT_PRINTF)
	@cp $(FT_PRINTF)/$(libftprintf) .
	@mv $(libftprintf) $(NAME)
	@make --quiet -C $(GNL)
	@cp $(GNL)/gnl.a .
	@mv gnl.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)libft compiled!$(DEF_COLOR)"

$(OBJ_DIR)/%.o: sources/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	@make --quiet clean -C $(FT_PRINTF)
	@make --quiet clean -C $(GNL)
	@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make --quiet fclean -C $(FT_PRINTF)
	@make --quiet fclean -C $(GNL)
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

.PHONY: all clean fclean re
.SILENT:
	all
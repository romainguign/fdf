# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:50:47 by roguigna          #+#    #+#              #
#    Updated: 2023/12/12 14:46:17 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBMLX_DIR = MacroLibX

all:
	clang -g ./sources/* -L libft -lft -L MacroLibX -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR) -I MacroLibX/includes -I libft/includes -I includes
	./a.out ./maps/42.fdf


re:
	clang -g ./sources/* ./libft/libft.a -Imlx  -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
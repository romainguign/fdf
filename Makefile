# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:50:47 by roguigna          #+#    #+#              #
#    Updated: 2023/12/06 12:50:48 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all":
	clang ./sources/* ./libft/libft.a -Imlx  -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
	./a.out ./maps/42.fdf
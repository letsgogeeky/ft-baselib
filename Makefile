# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:26:51 by ramoussa          #+#    #+#              #
#    Updated: 2023/07/07 19:01:40 by ramymoussa       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = baselib.a

LIBFT := libft
GNL := get-next-line
PRINTF := ftprintf
LIBFT_LIB = $(LIBFT)/libft.a
GNL_LIB := $(GNL)/getnextline.a
PRINTF_LIB := $(PRINTF)/libftprintf.a

all: $(NAME)

$(NAME): libft gnl printf
	
libft:
	cd $(LIBFT) && make

gnl:
	cd $(GNL) && make
	
printf:
	cd $(PRINTF) && make

clean:
	cd $(LIBFT) && make clean
	cd $(GNL) && make clean
	cd $(PRINTF) && make clean

fclean: clean
	cd $(LIBFT) && make fclean
	cd $(GNL) && make fclean
	cd $(PRINTF) && make fclean

re: fclean all

.PHONY: all libft clean fclean re

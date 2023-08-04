# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:26:51 by ramoussa          #+#    #+#              #
#    Updated: 2023/08/04 17:23:37 by ramymoussa       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = baselib.a

LIBFT := libft
GNL := get-next-line
PRINTF := ftprintf
LIBFT_LIB = $(LIBFT)/libft.a
GNL_LIB := $(GNL)/getnextline.a
PRINTF_LIB := $(PRINTF)/libftprintf.a
LIBS := ${LIBFT_LIB} ${PRINTF_LIB}
HEADERS := ${LIBFT}/libft.h ${GNL}/get_next_line.h ${PRINTF}/ft_printf.h
SRCS := ${GNL}/get_next_line.c \
			${GNL}/get_next_line_utils.c \
			$(PRINTF)/ft_printf.c \
			$(PRINTF)/hex_types.c \
			$(PRINTF)/string_types.c \
			$(PRINTF)/numeric_types.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): ${OBJS}
	make --directory=${LIBFT}
	cp ${LIBFT_LIB} $(NAME)
	ar -crs $(NAME) $(OBJS) && echo "Baselib Successful build...!"

clean:
	make clean --directory=$(LIBFT)
	make clean --directory=$(PRINTF)
	make clean --directory=$(GNL)

fclean:
	make fclean --directory=$(LIBFT)
	make fclean --directory=$(PRINTF)
	make fclean --directory=$(GNL)
	rm -rf baselib.a

re: fclean all

.PHONY: all libft clean fclean re

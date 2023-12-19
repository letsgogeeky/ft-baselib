# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:26:51 by ramoussa          #+#    #+#              #
#    Updated: 2023/12/19 20:13:32 by ramymoussa       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = baselib.a

RED_BOLD := \033[1;31m
GREEN := \033[0;32m
BLUE := \033[0;33m
CYAN := \033[0;36m
RESET_COLOR := \033[0m

LIBFT := libft
GNL := get-next-line
PRINTF := ftprintf
LIBFT_LIB = $(LIBFT)/libft.a
GNL_LIB := $(GNL)/getnextline.a
PRINTF_LIB := $(PRINTF)/libftprintf.a
LIBS := ${LIBFT_LIB} ${PRINTF_LIB}
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
	ar -crs $(NAME) $(OBJS) && echo "${GREEN}[BASELIB] Successful build...!${RESET_COLOR}"

clean:
	make clean --directory=$(LIBFT)
	make clean --directory=$(PRINTF)
	make clean --directory=$(GNL)
	@echo "${CYAN}[BASELIB] Removed all object files!${RESET_COLOR}"

fclean:
	make fclean --directory=$(LIBFT)
	make fclean --directory=$(PRINTF)
	make fclean --directory=$(GNL)
	rm -rf baselib.a
	@echo "${RED_BOLD}[BASELIB] Removed all object files archives!${RESET_COLOR}"

re: fclean all

.PHONY: all libft clean fclean re

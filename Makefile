# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygurma <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:22:06 by ygurma            #+#    #+#              #
#    Updated: 2023/03/17 20:12:53 by ygurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HEADER	= ft_printf.h
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCS	= ft_printf.c\
	  	parsing.c \
	  	type_processing.c \
	  	type_processing_hex.c \
	  	utils.c


OBJS	= $(SRCS:.c=.o)

AR = ar -rcs


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS) $(HEADER)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f  $(NAME)


re: fclean all

.PHONY:		all clean fclean re

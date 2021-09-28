# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seujeong <wjdzh8748@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 18:50:30 by dher              #+#    #+#              #
#    Updated: 2021/09/28 06:25:20 by seujeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -g -fsanitize=address # -Wall -Wextra -Werror
# SERVER		= server
# ClIENT		= client
LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
NAME		= extra.a
OBJS		= $(SRCS:.c=.o)
SRCS		= extra.c
INCS		= .
LIBC		= ar rc

all			: $(NAME)
	$(CC) $(CFLAGS) server.c $(NAME) -o server
	$(CC) $(CFLAGS) client.c $(NAME) -o client

bonus			: $(NAME)
	$(CC) $(CFLAGS) server.c $(NAME) -o server
	$(CC) $(CFLAGS) client.c $(NAME) -o client

$(NAME)	: $(LIBFT_LIB) $(OBJS)
	cp $(LIBFT_LIB) $@
	$(LIBC) $(NAME) $^

$(LIBFT_LIB)	:
	$(MAKE) -j 8 all -C $(LIBFT_DIR) CFLAGS+=-g

fclean		: clean
	$(RM) $(NAME) server client
	$(MAKE) fclean -C $(LIBFT_DIR)

clean		:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

re			: fclean all

.PHONY		: all fclean clean re retest debug test

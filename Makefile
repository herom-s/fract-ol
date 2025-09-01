# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/09/01 19:24:40 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

LIBFT_DIR := libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_LIB := $(LIBFT)

MLX_DIR := minilibx/
MLX := $(MLX_DIR)minilibx.a
MLX_LIB := -L$(MLX_DIR) -lmlx

SRCS = main.c \
	   env.c \
	   draw.c \
	   error.c \
	   window.c \
	   key_handler.c \
	   mouse_handler.c \
	   img_buffer.c \
	   args_handler.c \
	   fract.c \
	   fract_util.c \
	   mandelbrot_fract.c \
	   julia_fract.c

LIBFT_INC := $(LIBFT_DIR)inc/
MLX_INC := $(MLX_DIR)

DEPS := $(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm

CC = cc
CFLAGS = -I$(MLX_INC) -I$(LIBFT_INC) -Wall -Wextra -Werror

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0 -fsanitize=leak
endif

OBJS = $(SRCS:.c=.o)

RM = rm -f

.PHONY: all clean fclean re

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEPS) -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

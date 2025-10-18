# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/09/10 03:13:16 by hermarti         ###   ########.fr        #
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
	   color.c \
	   window.c \
	   key_handler.c \
	   mouse_handler.c \
	   img_buffer.c \
	   args_handler.c \
	   fract.c \
	   fract_util.c \
	   mandelbrot_fract.c \
	   julia_fract.c

SRCS_BONUS = main_bonus.c \
	   env_bonus.c \
	   draw_bonus.c \
	   error_bonus.c \
	   color_bonus.c \
	   window_bonus.c \
	   key_handler_bonus.c \
	   key_handler_util_bonus.c \
	   mouse_handler_bonus.c \
	   img_buffer_bonus.c \
	   args_handler_bonus.c \
	   args_handler_help_bonus.c \
	   args_handler_util_bonus.c \
	   fract_bonus.c \
	   fract_util_bonus.c \
	   mandelbrot_fract_bonus.c \
	   julia_fract_bonus.c \
	   burning_ship_fract_bonus.c \
	   mandelbrot3d_fract_bonus.c \
	   mandelbrot3d_fract_util_bonus.c \
	   julia3d_fract_bonus.c \
	   julia3d_fract_util_bonus.c \
	   vec_math_bonus.c

INC = fractol.h
INC_BONUS = fractol_bonus.h fractol_vec_math_bonus.h

LIBFT_INC := $(LIBFT_DIR)inc/
MLX_INC := $(MLX_DIR)

DEPS := $(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm

CC = cc
CFLAGS = -I$(MLX_INC) -I$(LIBFT_INC) -Wall -Wextra -Werror

OPT ?= 0
ifeq ($(OPT), 1)
	CFLAGS += -O3 -ffast-math
endif

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0 -fsanitize=leak
endif

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -f

.PHONY: all clean fclean re

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx

$(OBJS): %.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(INC_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEPS) -o $@

bonus: $(LIBFT) $(MLX) .bonus
	@:

.bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(DEPS) -o $(NAME)
	@touch .bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) .bonus

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/10/13 14:37:57 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

LIBFT_DIR := libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_LIB := $(LIBFT)

SLX_DIR := SampaLX/
SLX := $(SLX_DIR)libmlx.a
SLX_LIB := -L$(SLX_DIR) $(SLX)

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
SLX_INC := $(SLX_DIR)includes/

DEPS := $(LIBFT_LIB) $(SLX_LIB) -lGL -lglfw -lm

CC = cc
CFLAGS = -I$(SLX_INC) -I$(LIBFT_INC) -Wall -Wextra -Werror

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

.PHONY: all bonus clean fclean re web web-bonus webclean

all: $(LIBFT) $(SLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SLX):
	$(MAKE) -C $(SLX_DIR)

$(OBJS): %.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(INC_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(SLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(SLX_LIB) $(DEPS) -o $@

bonus: $(LIBFT) $(SLX) .bonus
	@:

.bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(SLX_LIB) $(DEPS) -o $(NAME)
	@touch .bonus

# --- SampaLX WebGL / Emscripten build ---

WEB_NAME := fractol.html
WEB ?= emcc

SLX_WEB := $(SLX_DIR)libmlx_web.a

WEB_SHELL := web/shell.html
WEB_PREJS := web/pre.js

WEB_CFLAGS := -I$(SLX_INC) -I$(LIBFT_INC) -O2 -Wall -Wextra
WEB_LDFLAGS := -sUSE_GLFW=3 -sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2 \
	-sALLOW_MEMORY_GROWTH=1

LIBFT_SRCS := $(wildcard $(LIBFT_DIR)src/*.c)
LIBFT_WEB_OBJS := $(LIBFT_SRCS:.c=.web.o)

$(SLX_WEB):
	$(MAKE) -C $(SLX_DIR) web

$(LIBFT_WEB_OBJS): %.web.o: %.c
	$(WEB) $(WEB_CFLAGS) -c $< -o $@

web: $(SLX_WEB) $(LIBFT_WEB_OBJS) $(WEB_SHELL) $(WEB_PREJS)
	$(WEB) $(WEB_CFLAGS) --shell-file $(WEB_SHELL) --pre-js $(WEB_PREJS) \
		$(SRCS) $(LIBFT_WEB_OBJS) $(SLX_WEB) $(WEB_LDFLAGS) -o $(WEB_NAME)

web-bonus: $(SLX_WEB) $(LIBFT_WEB_OBJS) $(WEB_SHELL) $(WEB_PREJS)
	$(WEB) $(WEB_CFLAGS) --shell-file $(WEB_SHELL) --pre-js $(WEB_PREJS) \
		$(SRCS_BONUS) $(LIBFT_WEB_OBJS) $(SLX_WEB) $(WEB_LDFLAGS) \
		-o $(WEB_NAME)

webclean:
	$(MAKE) -C $(SLX_DIR) webclean
	$(RM) $(LIBFT_WEB_OBJS)
	$(RM) $(WEB_NAME) $(WEB_NAME:.html=.js) $(WEB_NAME:.html=.wasm)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(SLX_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) .bonus
	$(RM) $(WEB_NAME) $(WEB_NAME:.html=.js) $(WEB_NAME:.html=.wasm)
	$(MAKE) -C $(SLX_DIR) webclean
	$(RM) $(LIBFT_WEB_OBJS)

re: fclean all

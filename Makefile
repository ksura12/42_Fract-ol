# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 09:24:12 by ksura             #+#    #+#              #
#    Updated: 2022/07/20 18:50:51 by ksura@student.42 ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC = gcc
CFLAGS := -Wall -Werror -Wextra
LIBRARIES = $(FT_LNK) 
LIBS = -lm
INCLUDES = $(FT_INC)
HEADER = ./header
SRCDIR = src/
OBJDIR := build/

LIBFT = $(LIBFT_DIRECTORY)/libft.a
LIBFT_DIRECTORY = ./libft
MINILIB_DIR = ./mlx
FT_INC	= -I ./libft/ -I ./mlx/
FT_LNK	= ./libft/libft.a

SRC := main.c mandelbrot.c colors.c moves.c zoom.c drawing.c\
		julia.c burning_ship.c my_pixel.c tools.c

OS = $(shell uname)
ifeq ($(OS), Linux)
	LIBS += -Lmlx -lmlx -L/usr/lib -Imlx -lX11 -lXext -lz 
	OBLI += -I/usr/inlcude -Imlx
	SRC += destroy_linux.c
endif
ifeq ($(OS), Darwin)
	LIBS += -Lmlx -lmlx -framework OpenGL -framework AppKit
	SRC += destroy_mac.c
endif

GREEN = \033[0;32m
RED = \033[0;31m



OBJS = ${SRC:.c=.o}
OBJECTS_PREF := $(addprefix $(OBJDIR), $(OBJS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIB) $(OBJECTS_PREF) $(OBJDIR)
	@$(CC) $(FLAGS) $(OBJECTS_PREF) $(LIBRARIES) -I$(HEADER) $(LIBS) -o $@
	@echo "$(GREEN)$(NAME) was created"
	
$(LIBFT):
	@cd ./$(LIBFT_DIRECTORY) && make all
	
$(MINILIB):
	@cd ./$(MINILIB_DIR) && make
	
$(OBJECTS_PREF): build/%.o : src/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(OBLI) -c $< -o $@ -I$(HEADER) $(INCLUDES)

clean:
	@cd ./$(LIBFT_DIRECTORY) && make clean
	@rm -rf $(OBJDIR)

fclean: clean
	@cd ./$(LIBFT_DIRECTORY) && make fclean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted"

re: fclean all

debug: $(LIBFT) $(OBJECTS_PREF) $(OBJDIR)
	$(CC) $(FLAGS) $(OBJECTS_PREF) $(LIBRARIES) -I$(HEADER) -o $(NAME) -g
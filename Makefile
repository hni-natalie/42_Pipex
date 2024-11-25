# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:25:02 by hni-xuan          #+#    #+#              #
#    Updated: 2024/08/28 15:25:22 by hni-xuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags 
CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

# Output file name 
NAME = pipex

SRC_DIR = src

SRCS_FILES = pipex.c utils.c 

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./Libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Generates output file
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

# Removes objects
clean: 
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

# Removes objects and excutables 
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# Removes objects and excutables and remkaes
re: fclean all 
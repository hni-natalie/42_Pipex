# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:25:02 by hni-xuan          #+#    #+#              #
#    Updated: 2024/11/26 08:45:43 by hni-xuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags 
CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

# Output file name 
NAME = pipex

SRC_DIR = src
BONUS_SRC_DIR = bonus

SRCS_FILES = pipex.c utils.c 
BONUS_SRC_FILES = pipex_bonus.c pipex_utils_bonus.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC_FILES))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

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

bonus: $(BONUS_OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

# Removes objects
clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_PATH) clean

# Removes objects and excutables 
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# Removes objects and excutables and remkaes
re: fclean all 


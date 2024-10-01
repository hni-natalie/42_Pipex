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
CC = CC
CFLAGS = -Wall - Werror -Wextra
RM = rm -fclean

# Output file name 
NAME = pipex.a

SRCDIR = src/
OBJDIR = bin/
INCDIR = -Iinclude

SRCS_FILES = 

SRCS = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCS_FILES)))

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	ar rcs $@ $^

# Compiles sources into objects
$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

# Removes objects
clean: 
	$(RM) $(OBJS)

# Removes objects and excutables 
fclean: clean
	$(RM) $(NAME)

# Removes objects and excutables and remkaes
re: fclean all 
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:48:51 by nnourine          #+#    #+#              #
#    Updated: 2024/03/12 10:40:15 by nnourine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
COLOR = \033[0;34m
RESET_COLOR = \033[0m

# Executable name
NAME = philo

# Compiler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
ADDRESS_SANITIZE = -fsanitize=address
THREAD_SANITIZE = -fsanitize=thread
LLDB = -g
PTHREAD = -lpthread

# Directories
SRCDIR = src/c_files
INCDIR = include

# Files
SRCS =  $(SRCDIR)/ft_putstr_fd.c \
		$(SRCDIR)/exit.c \
		$(SRCDIR)/philo.c
		
OBJS = $(SRCS:.c=.o)

# Phony targets
.PHONY: all clean fclean re address thread lldb

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $@
	@echo "$(COLOR)Compiling and linking: done$(RESET_COLOR)"

# Compiling
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Clean-up
clean:
	@$(RM) $(OBJS)
	@echo "$(COLOR)Clean-up: done$(RESET_COLOR)"

# Full clean
fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "$(COLOR)Full clean: done$(RESET_COLOR)"

# Recompile
re: fclean all

# Address sanitizer
address: fclean
address: CFLAGS += $(ADDRESS_SANITIZE)
address: all

# Thread sanitizer
thread: fclean
thread: CFLAGS += $(THREAD_SANITIZE)
thread: all

# LLDB
lldb: fclean
lldb: CFLAGS += $(LLDB)
lldb: all
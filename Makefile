# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:48:51 by nnourine          #+#    #+#              #
#    Updated: 2024/03/22 13:02:39 by nnourine         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -o2 
ADDRESS_SANITIZE = -fsanitize=address
THREAD_SANITIZE = -fsanitize=thread
LLDB = -g
PTHREAD = -pthread

# Directories
SRCDIR = src/c_files
INCDIR = include

# Files
SRCS =  $(SRCDIR)/atoi_error.c \
		$(SRCDIR)/putstr_fd.c \
		$(SRCDIR)/print_error.c \
		$(SRCDIR)/lock_print.c \
		$(SRCDIR)/strncmp.c \
		$(SRCDIR)/wait.c \
		$(SRCDIR)/find_fork.c \
		$(SRCDIR)/data.c \
		$(SRCDIR)/fork.c \
		$(SRCDIR)/philo.c \
		$(SRCDIR)/info.c \
		$(SRCDIR)/input.c \
		$(SRCDIR)/thread.c \
		$(SRCDIR)/main.c
		
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
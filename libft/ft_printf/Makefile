# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 13:15:49 by tday	           #+#    #+#              #
#    Updated: 2023/10/08 17:39:10 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libftprintf.a
SRCDIR	= sources
INCDIR	= includes
SRCFILE	= ft_printf.c ft_character.c ft_decimal_integer.c ft_hexadecimal.c \
		  ft_pointer.c ft_string.c ft_unsigned_integer.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS	= $(SRCS:.c=.o)
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR)
AR		= ar -rcs
RM		= rm -f	

# Colours

DEFAULT_COLOUR = \033[0m
GRAY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

# Recipes

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CYAN)$(NAME) compiled successfully!$(DEFAULT_COLOUR)"

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)printf object files deleted.$(DEFAULT_COLOUR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)$(NAME) deleted.$(DEFAULT_COLOUR)"

re: fclean all

# Phony

.PHONY: all clean fclean re
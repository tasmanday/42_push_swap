# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 14:30:00 by tday              #+#    #+#              #
#    Updated: 2023/09/09 14:30:00 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libft.a
SRCDIR	= sources
INCDIR	= includes 
SRCFILE = ft_abs.c ft_atoi.c ft_bzero.c ft_calloc.c ft_count_words.c\
		  ft_fabs.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
		  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		  ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		  ft_substr.c ft_tolower.c ft_toupper.c ft_swap.c ft_round_up.c\
		  ft_atolong.c ft_strcmp.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))		    
OBJS	= $(SRCS:.c=.o)
CC		= cc
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
	@echo "$(MAGENTA)libft object files deleted.$(DEFAULT_COLOUR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)$(NAME) deleted.$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all clean fclean re
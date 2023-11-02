# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 22:30:42 by tday              #+#    #+#              #
#    Updated: 2023/11/02 13:55:05 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= push_swap
GNL_DIR		= libft/get_next_line
LFT_DIR		= libft/libft
PRF_DIR 	= libft/ft_printf
INC_DIR		= includes
SRC_DIR		= sources
GNL_LIB		= $(GNL_DIR)/libgnl.a
LFT_LIB		= $(LFT_DIR)/libft.a
PRF_LIB 	= $(PRF_DIR)/libftprintf.a
SRC_FILES	= main.c initialisation.c errors.c swap.c push.c rotate.c \
			rev_rotate.c push_swap.c min_med_max.c best.c move_pair_to_top.c\
			find_pos_and_move.c misc_utils.c sort_1.c sort_2.c alt_sort.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(SRCS:%.c=%.o)
AR			= ar -rcs
RM			= rm -f
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
DEBUG_FLAGS	= -fsanitize=address -g

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

$(NAME): $(GNL_LIB) $(LFT_LIB) $(PRF_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(GNL_DIR) -lgnl -L$(LFT_DIR) -lft -L$(PRF_DIR) -lftprintf -o $(NAME)
	@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)$(NAME)$(DEFAULT_COLOUR)"

$(GNL_LIB):
	@$(MAKE) all -s -C $(GNL_DIR)
	@echo "\n"

$(LFT_LIB):
	@$(MAKE) -s -C $(LFT_DIR)
	@echo "\n"

$(PRF_LIB):
	@$(MAKE) -s -C $(PRF_DIR)
	@echo "\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(DEFAULT_COLOUR)"

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

objclean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)local object files deleted.$(DEFAULT_COLOUR)"

clean: objclean
	@$(MAKE) clean -s -C $(GNL_DIR)
	@echo "$(RED)cleaned gnl.$(DEFAULT_COLOUR)"
	@$(MAKE) clean -s -C $(LFT_DIR)
	@echo "$(RED)cleaned libft.$(DEFAULT_COLOUR)"
	@$(MAKE) clean -s -C $(PRF_DIR)
	@echo "$(RED)cleaned ft_printf.$(DEFAULT_COLOUR)"

fclean: objclean
	@$(MAKE) fclean -s -C $(GNL_DIR)
	@echo "$(RED)fcleaned gnl.$(DEFAULT_COLOUR)"
	@$(MAKE) fclean -s -C $(LFT_DIR)
	@echo "$(RED)fcleaned libft.$(DEFAULT_COLOUR)"
	@$(MAKE) fclean -s -C $(PRF_DIR)
	@echo "$(RED)fcleaned ft_printf.$(DEFAULT_COLOUR)"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Deleted executable: $(WHITE)$(NAME).$(DEFAULT_COLOUR)"

re: fclean all

.PHONY: all objclean clean fclean re
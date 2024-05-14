# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 13:47:54 by ayhamdou          #+#    #+#              #
#    Updated: 2024/05/11 15:25:27 by ayhamdou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = push_swap.h
LIB = pushSwap.a
BNSLIB = bonus.a
GNLH = get_next_line.h
NAME = push_swap
BNSNAME = checker

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAIN1 = push_swap.c
MAIN2 = bonus_checker.c

SRCS = ./utils/utils1.c utils/linkedlistfunc.c utils/ft_split.c \
		operations/operations1.c operations/core_operations.c operations/operations2.c operations/oneop_create_list.c\
		error_handlers/errors_checker.c error_handlers/is_valid.c\
		sorting_funcs/sort_three.c sorting_funcs/sort_four.c sorting_funcs/sort_five.c sorting_funcs/sort_n.c sorting_funcs/sort_n_utils.c\
		utils/get_next_line/get_next_line_utils.c

BNSSRCS = bonus/bonus_checker.c\
		utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c


OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
BNSOBJS = $(addprefix $(OBJS_DIR)/, $(BNSSRCS:%.c=%.o))
LIB = pushSwap.a

vpath %.c sorting_funcs operations error_handlers utils utils/get_next_line bonus

all : $(NAME)
	@echo "COMPILED !"

$(NAME) : $(LIB) $(MAIN1)
	$(CC) $(FLAGS) $(LIB) $(MAIN1) -o $@

$(LIB) : $(OBJS)
	@ar -rcs $(LIB) $(OBJS)

$(BNSLIB) : $(BNSOBJS)
	@ar -rcs $(BNSLIB) $(BNSOBJS)


$(OBJS_DIR)/%.o : %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(BNSNAME) : $(BNSLIB) $(LIB)
	@$(CC) $(FLAGS) $(BNSLIB) $(LIB) -o $(BNSNAME)

bonus : $(BNSNAME)
	@echo "bonus COMPILED!"

clean:
	@$(RM) $(OBJS) $(BNSOBJS)

fclean: clean
	@$(RM) $(NAME) $(LIB) $(BNSLIB) $(BNSNAME)

re: fclean all

.PHONY: all clean fclean re bonus 

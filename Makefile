NAME		=	push_swap
NAME_BONUS	=	checker

SRCS		= 	./src/push_swap.c\
				./src/mini_sort.c\
				./src/sorting.c\
				./src/validation.c\
				./src/print_stacks.c\
				./src/error_handling.c\
				./src/extraSorting.c\
				./src/get_stack.c\
				./src/init.c\
				./commands/swap.c\
				./commands/push.c\
				./commands/rotate.c\
				./commands/reverse_rotate.c\
				 ./src/bubbleSorting.c

SRCS_BONUS	=	./src/checker.c\
				./src/validation.c\
				./src/print_stacks.c\
				./src/error_handling.c\
				./src/init.c\
				./commands/swap.c\
				./commands/push.c\
				./commands/rotate.c\
				./commands/reverse_rotate.c\
				./gnl/get_next_line.c\
				./gnl/get_next_line_utils.c\
				 ./src/bubbleSorting.c

OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_BONUS))

INCLUDE		=	-I.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f

LIB = ./libft/libft.a

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY:		all libft clean fclean re

all:		libft $(NAME) $(NAME_BONUS)

libft:
			@$(MAKE) -C $(dir $(LIB))

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS) $(LIB)
			@$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)
			@echo ${GREEN} "\n< Push_swap binary -> done >\n" ${END}

$(NAME_BONUS):	libft $(OBJS_B) $(LIB)
			@$(CC) $(INCLUDE) $(LIB) -o $(NAME_BONUS) $(OBJS_B)
			@echo ${PURPLE} "\n< Checker binary -> done >\n" ${END}

clean:
			@$(RM) $(OBJS) $(OBJS_B)
			@$(MAKE) -C $(dir $(LIB)) clean
			@echo ${YELLOW} "\n< .o files -> removed >\n" ${END}

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo ${YELLOW} "\n< Binaries -> removed >\n" ${END}

re:			fclean all
			@echo ${PURPLE} "\n< Remake done >\n" ${END}

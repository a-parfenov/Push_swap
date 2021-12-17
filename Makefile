NAME		=	push_swap

SRCS_FILES	= 	push_swap.c		mini_sort.c\
				swap.c			sorting.c\
				push.c			validation.c\
				rotate.c\
				reverse_rotate.c

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

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

all:		libft $(NAME)

libft:
	@$(MAKE) -C $(dir $(LIB))

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS) $(LIB)
			@$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)
			@echo ${GREEN} "\n< Compiled push_swap >\n" ${END}

clean:
			@$(RM) $(OBJS)
			@$(MAKE) -C $(dir $(LIB)) clean
			@echo ${YELLOW} "\n< Cleaning succeed >\n" ${END}

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)
			@echo ${YELLOW} "\n< All created files were deleted >\n" ${END}

re:			fclean all
			@echo ${PURPLE} "\n< Remake done >\n" ${END}

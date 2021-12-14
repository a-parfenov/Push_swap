NAME = libft.a

SRCS = 		ft_isalpha.c		ft_isdigit.c		ft_isalnum.c\
			ft_isascii.c		ft_isprint.c		ft_strlen.c\
			ft_memset.c			ft_bzero.c			ft_memcpy.c\
			ft_memmove.c		ft_strlcat.c		ft_strlcpy.c\
			ft_toupper.c		ft_tolower.c		ft_strchr.c\
			ft_strrchr.c		ft_strncmp.c		ft_strncmp.c\
			ft_memchr.c			ft_memcmp.c			ft_strnstr.c\
			ft_putchar_fd.c		ft_putstr_fd.c		ft_atoi.c\
			ft_putendl_fd.c		ft_split.c			ft_strdup.c\
			ft_calloc.c			ft_putnbr.c		ft_substr.c\
			ft_strjoin.c		ft_itoa.c			ft_strmapi.c \
			ft_strtrim.c		ft_striteri.c

SRCS_B	=	ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c\
			ft_lstlast.c		ft_lstadd_back.c		ft_lstdelone.c\
			ft_lstclear.c		ft_lstiter.c			ft_lstmap.c

OBJ		=	$(SRCS:%.c=%.o)
OBJ_B	=	$(SRCS_B:%.c=%.o)
HEADERS	=	libft.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.$(HEADERS)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME):	$(OBJ) $(HEADERS)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\033[1;32m\n< Compiled libft >\n\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(OBJ_B) $(HEADERS)
	@ar rc $(NAME) $(OBJ_B)

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
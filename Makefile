CC		=	gcc

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft

HDRS	=	./

SRCS	:=	ft_printf.c ft_printf_utils.c print_chars.c \
			print_digits.c ft_parser.c ft_converter.c
OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
		make -C $(LIBFT)
		cp libft/libft.a ./$(NAME)
		ar	rcs	$(NAME)	$(OBJS)

.c.o:
		$(CC) $(CFLAGS) -I $(HDRS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re

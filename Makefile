CC		=	gcc

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

TESTNAME = test

TESTFLAGS = -Wno-format

TESTFILES = main_test.c

LIBFT	=	libft

HDRS	=	./

SRCS	:=	ft_printf.c ft_printf_utils.c print_chars.c \
			print_digits.c ft_parser.c ft_converter.c ft_printf_bonus.c
OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
		make -C $(LIBFT)
		cp libft/libft.a ./$(NAME)
		ar	rcs	$(NAME)	$?

bonus: $(NAME)

.c.o:
		$(CC) $(CFLAGS) -I $(HDRS) -c $< -o $(<:.c=.o)

test:	all

		$(CC) $(TESTFLAGS) $(TESTFILES) $(NAME) $(OBJS) -o $(TESTNAME)

surprise: all
		$(CC) surprise_test.c $(NAME) $(OBJS) -o surprise

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME) $(TESTNAME) surprise
		make fclean -C $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re

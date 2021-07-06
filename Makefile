SRCDIR	= ./srcs/
SRCNAME	=	main.c\
			command.c\
			status.c\
			ft_malloc.c\
			utility1.c\
			mini_libft1.c\
			debug.c

SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)
NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

sani	:	$(OBJS)
		$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re bonus

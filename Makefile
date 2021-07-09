SRCDIR	= ./srcs/
SRCNAME	=	main.c\
			pipe.c\
			execve.c\
			execve_search.c\
			redirect.c\
			command.c\
			status.c\
			ft_close.c\
			ft_malloc.c\
			utility1.c\
			mini_libft1.c\
			mini_libft2.c\
			mini_libft3.c

SRCBONUSNAME =	main_bonus.c\
				pipe.c\
				execve.c\
				execve_search.c\
				redirect.c\
				command.c\
				status.c\
				ft_close.c\
				ft_malloc.c\
				utility1.c\
				mini_libft1.c\
				mini_libft2.c\
				mini_libft3.c

SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
SRCSBONUS	= $(addprefix $(SRCDIR), $(SRCBONUSNAME))
OBJS	= $(SRCS:.c=.o)
OBJSBONUS	= $(SRCSBONUS:.c=.o)
NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

.c.o	:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus	:	$(OBJSBONUS)
			$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAME)

sani	:	$(OBJS)
		$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re bonus

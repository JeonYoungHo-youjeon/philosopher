NAME = philo

SRCS		=	main.c \
				action.c \
				init.c \
				utils.c \
				
OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		gcc -o $(NAME) $(OBJS)

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		
fclean		:	clean
		rm -f $(NAME)
		
re			:	fclean all

.PHONY		:	all clean fclean re bonus

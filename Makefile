SRCS		= 	ft_printf.c					\
				check_flags.c				\
				ft_printf_utils1.c			\
				ft_itoa.c					\
				print_d.c					\
				print_s.c					\
				print_c.c					\
				print_percent.c				\
		
OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${BOBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
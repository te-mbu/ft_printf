SRCS		= 	ft_printf.c					\
				check_flags.c				\
				ft_printf_utils1.c			\
				ft_printf_utils2.c			\
				ft_printf_utils3.c			\
				ft_printf_utils4.c			\
				ft_printf_utils5.c			\
				ft_itoa.c					\
				ft_itoa_base.c				\
				ft_itoa_base_p.c			\
				print_d.c					\
				print_d2.c					\
				print_d3.c					\
				print_d4.c					\
				print_s.c					\
				print_s2.c					\
				print_c.c					\
				print_p.c					\
				print_percent.c				\
				print_percent2.c			\
				ft_zero_case.c				\
		
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

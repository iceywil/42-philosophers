# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 15:31:15 by wscherre          #+#    #+#              #
#    Updated: 2024/09/02 19:30:48 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =   main.c \
			actions.c \
			tools.c \
			check.c \
			monitor.c \
			routine.c \

OBJS    =   $(SRCS:.c=.o)

CC  	=   cc

RM 		=  	rm -f

CFLAGS  =   -Wall -Wextra -Werror -pthread

NAME    =   philo

all: $(NAME)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
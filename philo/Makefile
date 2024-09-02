# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 15:31:15 by wscherre          #+#    #+#              #
#    Updated: 2024/09/02 17:39:53 by wscherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =   srcs/main.c \
			srcs/actions.c \
			srcs/tools.c \
			srcs/check.c \
			srcs/monitor.c \
			srcs/routine.c \

OBJS    =   $(SRCS:.c=.o)

CC  	=   cc

RM 		=  	rm -f

CFLAGS  =   -Wall -Wextra -Werror -I. -MMD -pthread

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
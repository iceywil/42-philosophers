# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a <a@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 15:31:15 by wscherre          #+#    #+#              #
#    Updated: 2024/08/20 22:40:04 by a                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =   srcs/philosophers.c \
			srcs/actions.c \
			srcs/tools.c \
			srcs/check.c \
			srcs/monitor.c \

OBJS    =   $(SRCS:.c=.o)

DEPS 	= 	$(SRCS:.c=.d)

CC  	=   cc

RM 		=  	rm -f

CFLAGS  =   -Wall -Wextra -Werror -I. -MMD -pthread

NAME    =   philosophers

all: $(NAME)

-include ${DEPS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
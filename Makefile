# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 15:31:15 by wscherre          #+#    #+#              #
#    Updated: 2024/05/01 15:44:35 by wscherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =   srcs/pipex.c \
			srcs/pipex_utils.c \
			srcs/free_all.c \
			srcs/open_files.c \
			srcs/parsing.c \
			srcs/pipes.c \

OBJS    =   $(SRCS:.c=.o)

DEPS 	= 	$(SRCS:.c=.d)

CC  	=   cc

RM 		=  	rm -f

CFLAGS  =   -Wall -Wextra -Werror -I. -MMD

NAME    =   philosophers

LIBFT 	= 	libft/libft.a

all: $(NAME)

-include ${DEPS}

${LIBFT}:
	make -C libft

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} $(OBJS) $(LIBFT) $(MLX_EX) -o $(NAME) -lm 

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
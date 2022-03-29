# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 18:47:30 by nargouse          #+#    #+#              #
#    Updated: 2022/03/29 18:53:33 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
INCLUDE = ./include/
CFLAGS	+= -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread

FILES	= main.c parsing.c init_threads.c thread.c life.c death.c quit.c utils.c

SRCS	= $(addprefix ./srcs/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@

objs/%.o: srcs/%.c
	mkdir -p ./objs/
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

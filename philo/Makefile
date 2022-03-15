# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 22:41:32 by nargouse          #+#    #+#              #
#    Updated: 2022/03/15 16:55:06 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
INCLUDE = ./include/
CFLAGS	+= -Wall -Werror -Wextra

FILES	= main.c parsing.c utils.c thread.c

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

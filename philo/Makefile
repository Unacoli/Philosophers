# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 22:41:32 by nargouse          #+#    #+#              #
#    Updated: 2022/03/03 20:59:03 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
INCLUDE = ./include/
CFLAGS	+= -Wall -Werror -Wextra

FILES	= main.c

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

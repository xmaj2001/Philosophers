# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 13:01:54 by xjose             #+#    #+#              #
#    Updated: 2024/10/16 02:03:53 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

FILE_SRC = main.c utils.c init.c philo_status.c philo_utils.c routines.c

FLAGS		= -Wall -Wextra -Werror

objects		= $(FILE_SRC:.c=.o)

CP			= cc

all:$(NAME)

$(NAME):
	$(CP) $(FILE_SRC) $(FLAGS) -c
	$(CP) $(objects) -o $(NAME)

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(NAME)

re: fclean all

rec: fclean all
	rm -f $(objects)

recc: fclean all
	rm -f $(objects)
	clear

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 13:01:54 by xjose             #+#    #+#              #
#    Updated: 2024/09/24 22:32:31 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= philo

FILE_SRC = *.c

# FLAGS		= -fsanitize=thread -g

CP			= cc

all:$(NAME)

$(NAME):
	$(CP) $(FLAGS) $(FILE_SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

rec: fclean all
	rm -f *.o

recc: fclean all
	rm -f *.o
	clear

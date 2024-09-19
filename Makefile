# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 13:01:54 by xjose             #+#    #+#              #
#    Updated: 2024/09/19 13:25:05 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= app

FILE_SRC = *.c

FLAGS		= -fsanitize=thread -g

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
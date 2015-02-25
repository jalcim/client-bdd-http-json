#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 13:59:15 by nbahri            #+#    #+#              #
#    Updated: 2014/06/06 19:38:07 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_inet.a

SRC =	ft_inetaddr.c\
	ft_readfd.c\
	ft_reip.c\
	ft_rinetaddr.c\
	ft_sock.c\
	ft_sock_in_file.c\
	locate.c\
	error.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC)
		ar rc $(NAME) $(SRCO)
		ranlib $(NAME)
clean:
		/bin/rm -f $(SRCO)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 05:54:35 by jalcim            #+#    #+#              #
#    Updated: 2014/06/11 01:26:34 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CLT = client

CSRC =	object.c bdd/bdd.c dclient/config_request.c dclient/connecttest.c\
	dfile/mod_json.c dfile/object_sig_json.c dfile/parse_json.c dfile/file_gest.c

LIB =	libft/libft.a \
	libsock/ft_inet.a
#	bdd/bdd.a

FLAG = -g -Wall -Werror -Wextra

all : $(CLT)

$(CLT):
	gcc $(FLAG) $(LIB) $(CSRC) -o $(CLT)
clean:
		

fclean: clean
	rm $(CLT)

re: fclean all

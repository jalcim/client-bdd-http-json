#******************************************************************************#
# #
# ::: :::::::: #
# Makefile :+: :+: :+: #
# +:+ +:+ +:+ #
# By: jalcim <jalcim@student.42.fr> +#+ +:+ +#+ #
# +#+#+#+#+#+ +#+ #
# Created: 2013/11/23 22:52:49 by jalcim #+# #+# #
# Updated: 2013/12/25 09:01:22 by jalcim ### ########.fr #
# #
#******************************************************************************#

NAME = libft.a

SRC = ft_atoi.c ft_isprint.c ft_memcpy.c ft_putendl.c \
ft_strdel.c ft_strlcat.c ft_strncpy.c ft_strstr.c \
ft_bzero.c ft_itoa.c ft_memdel.c ft_putendl_fd.c \
ft_strlen.c ft_strnequ.c ft_strsub.c ft_strchr.c \
ft_isalnum.c ft_memalloc.c ft_memmove.c ft_putnbr.c \
ft_strequ.c ft_strmap.c ft_strnew.c ft_strtrim.c \
ft_isalpha.c ft_memccpy.c ft_memset.c ft_putnbr_fd.c \
ft_striter.c ft_strmapi.c ft_strnstr.c ft_tolower.c \
ft_isascii.c ft_memchr.c ft_putchar.c ft_strcmp.c \
ft_striteri.c ft_strncat.c ft_strrchr.c ft_toupper.c \
ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_putstr.c \
ft_strncmp.c ft_strsplit.c ft_strcat.c ft_strdup.c \
ft_strclr.c ft_strcpy.c ft_strjoin.c ft_putstr_fd.c \
ft_realloc.c ft_strlcar.c ft_printf.c ft_strrcpy.c \
ft_strrncpy.c ft_strrlcar.c ft_rbzero.c ft_power.c \
ft_int_len.c ft_read_chain.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I .
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
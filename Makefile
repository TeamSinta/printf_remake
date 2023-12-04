# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mshegow <mshegow@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/13 16:06:36 by mshegow       #+#    #+#                  #
#    Updated: 2023/12/04 16:58:56 by mshegow       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DIRSRC = ./srcs/
DIRINC = ./includes/
DIROBJ = ./objs/
DIRLIB = ./libft/

SRC = ft_printf print_str print_nbr print_hex print_ptr print_unsigned 
SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))
HEAD = ./includes/ 
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
NAMELFT = libft.a
CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -I${DIRINC} -I${DIRLIB}

$(NAME): ${OBJS}
	cd ${DIRLIB} && ${MAKE}
	cp -v ${DIRLIB}${NAMELFT} ${NAME}
	${AR} ${NAME} ${OBJS}
	${RN} ${NAME}

all: $(NAME)

clean:
	${RM} ${OBJS}
	cd ${DIRLIB} && ${MAKE} clean

fclean: clean
	${RM} $(NAME)
	cd ${DIRLIB} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re
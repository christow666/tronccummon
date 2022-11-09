NAME = libftprintf.a

SRCS =  ./srcs/ft_printf.c\
		./srcs/ft_format.c

LIBFT_A = ./libft/libft.a

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: alibft ${NAME}

alibft: 
	@(cd ./libft && make all)
	@(cd ..)

clean:
				rm -f *~ ${OBJ}

${NAME}: ${OBJ}
	@echo "making ${NAME}..."
	cp libft/libft.a ${NAME}
	${AR} ${NAME} ${OBJ} ${LIBFT_A}

fclean: clean
	rm -f ${NAME}
	@(cd ./libft && make fclean)
	@(cd ..)

re: fclean all

push:	
	@(git add .)
	@(git commit -m "backup")
	@(git push)
	@clear
NAME = printf.a

SRC = 

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: alibft ${NAME}

alibft: 
	@(cd ./libft && make all)
	@(cd ..)

clean:
				rm -f *~ ${OBJ} ${BOBJ}

${NAME}: ${OBJ}
	@echo "making ${NAME}..."
	${AR} ${NAME} ${OBJ} 

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
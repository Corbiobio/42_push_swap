.PHONY: all clean fclean re makelib 

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_FILE =	main.c\
			utils.c\
			operation.c\
			instruction.c\
			stack.c\
			average_sort.c\
			fastest_to_top.c\
			fastest_to_sort.c\
			sort.c

OBJ = ${SRC_FILE:.c=.o}

LIB_NAME = libft.a
LIB_DIR = libft/

INC = -I . -I ${LIB_DIR}

ARR = 8 9 10 7 6 4 5 3 1 2 0

%.o: %.c 
	${CC} ${CFLAGS} ${INC} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ} push_swap.h
	${MAKE} makelib
	${CC} ${CFLAGS} -g3 ${INC} ${OBJ} ${LIB_NAME} -o ${NAME}

makelib:
	${MAKE} -C ${LIB_DIR}
	cp ${LIB_DIR}${LIB_NAME} ${LIB_NAME}

clean:
	rm -f ${OBJ}

fclean: 
	${MAKE} -C ${LIB_DIR} fclean
	${MAKE} clean
	rm -f ${LIB_NAME}
	rm -f ${NAME}

re:
	${MAKE} fclean
	${MAKE} all

run:
	${MAKE}
	./${NAME} ${ARR}

val:
	${MAKE}
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./${NAME} ${ARR}
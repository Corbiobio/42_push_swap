.PHONY: all clean fclean re makelib 

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_FILE =	main.c\
			operation.c\
			instruction.c\
			stack.c\
			average_sort.c\
			search.c

OBJ = ${SRC_FILE:.c=.o}

LIB_NAME = libft.a
LIB_DIR = libft/

INC = -I . -I ${LIB_DIR}

ARR = 79 71 45 74 85 72 90 61 96 64 19 63 39 9 3 56 65 73 37 68 11 94 21 40 13 80 97 27 16 53 55 5 4 58 59 29 52 35 0 34 60 93 48 28 46 92 2 14 17 36 82 42 26 51 88 75 87 43 49 23 44 30 91 62 78 15 99 7 1 6 47 24 22 10 31 32 8 98 76 81 89 77 70 86 57 66 67 41 84 12 18 38 95 20 69 33 50 25 54 83

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
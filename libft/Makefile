.PHONY: all clean fclean re

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE_DIR = include/

INC = -I $(INCLUDE_DIR)

C_FILE =	ft_strlen.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_isprint.c\
			ft_isdigit.c\
			ft_isascii.c\
			ft_isalpha.c\
			ft_isalnum.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strchr.c\
			ft_strchr_index.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_striteri.c\
			ft_strmapi.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_abs.c\
			ft_strndup.c\
			get_next_line.c\
			free_double_pt.c\
			ft_atoi_protected.c

SRC_FILE := $(addprefix $(SRC_DIR), $(C_FILE))

OBJ = $(C_FILE:.c=.o)
OBJ := $(addprefix $(OBJ_DIR), $(OBJ))

all:
	$(MAKE) $(NAME)

$(NAME): .NotRelink

.NotRelink: $(OBJ)
	ar -rc $(NAME) $(OBJ)
	touch .NotRelink

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE_DIR)libft.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re libft bonus check run val

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE_DIR = include/

C_FILE =\
	push_swap.c\
	utils.c\
	operation.c\
	instruction.c\
	stack.c\
	verif_and_split_arg.c\
	parsing/arg_to_int_array.c\
	parsing/array_to_indexed_array.c\
	sorting/sort_quarter.c\
	sorting/get_fastest_to_top.c\
	sorting/get_fastest_to_sort.c\
	sorting/sort.c\
	sorting/sort_small_stack.c

SRC_FILE := $(addprefix $(SRC_DIR), $(C_FILE))

OBJ = $(C_FILE:.c=.o)
OBJ := $(addprefix $(OBJ_DIR), $(OBJ))

C_FILE_BONUS =\
	utils.c\
	verif_and_split_arg.c\
	instruction.c\
	operation.c\
	stack.c\
	parsing/arg_to_int_array.c\
	bonus/checker_bonus.c\
	bonus/instruction_fake_bonus.c

OBJ_BONUS = $(C_FILE_BONUS:.c=.o)
OBJ_BONUS := $(addprefix $(OBJ_DIR), $(OBJ_BONUS))

LIBFT_NAME = libft.a
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)$(LIBFT_NAME)

INC = -I $(INCLUDE_DIR) -I $(LIBFT_DIR)include

ARR = 133998 -461297 178990 -412821 -373669 197529 -107293 238409 -33284 302981 184108 -68183 331243 226417 -214140 -483438 -203294 -179375 -346330 158071 11522 -433335 -234466 -455866 335862 -494266 -369115 245365 -495570 465731 184196 -49150 196716 -426389 -45818 17734 -19205 -292864 110682 467712 131091 -477429 186924 -61610 -290123 -203711 -108325 242857 49646 -69160 -223081 486337 295681 60420 499040 493555 463852 -202143 -228105 -333175 -423465 -486312 397461 -101058 390252 97182 159978 265006 -5891 108665 323095 104896 314449 253083 -424962 160183 -236856 -17200 408979 -461202 237714 319062 222710 124628 -259357 24313 -443591 -480636 35460 151849 363165 267958 -266103 332092 -150272 -460894 -426710 474482 494869 21624 -388038 -329439 391596 301275 386899 448946 149634 273998 218957 -163096 -95559 76274 192026 298186 -290377 -43007 -300589 -178032 -158913 27629 438192 456042 -254917 -295409 -324928 217038 -158558 250380 255791 142584 138194 417809 23225 401460 -405346 -248467 199246 -404515 -231349 100368 89199 -375378 -455051 486162 298252 -169669 215153 -455675 -482143 425168 -52110 -401383 494357 -482895 394473 -421126 -232687 321731 214691 300359 215913 411685 -196475 303167 -346493 329633 178319 -282239 -8397 -141774 444028 -131851 347682 419448 448081 -297167 208220 -213867 168778 -487954 401631 476562 -321580 196080 31128 -27429 20826 -324117 196463 419037 -196992 115631 -281679 -152948 48588 -44980 372996 197601 -397453 -465124 471145 -397380 -25066 -51939 -31115 -87860 -227414 289946 -69235 277866 -235998 477289 354649 -338869 32486 -499909 77279 -353109 -157800 -382162 -134500 252532 -138654 -328336 -66021 162579 129115 -63375 296799 -401930 -494213 129809 -62962 -245319 -479956 248597 -499249 189950 -360617 -287475 247772 -429610 -225354 267385 343001 345212 310985 163921 -139385 203712 286076 109903 220242 -455702 -196353 179718 291012 -13585 -55692 -406267 121127 58419 71482 -328752 -261642 -179408 -350708 -264542 -351548 494132 -377218 479221 295876 20851 343396 -8058 -354739 396075 -10837 -353625 437928 -419447 311425 481185 155986 380948 -110612 429453 -322455 18327 -375582 332056 -37714 313549 -421179 57347 455660 314770 -473318 -122118 -421532 -229627 -207363 322975 139269 152434 394880 -138345 57339 -21927 -247744 -217116 -484216 214801 -411967 -377617 125956 -269268 -48568 10273 -425310 166601 89876 -407883 -141053 -469526 -268578 204980 -234747 210661 158024 334824 -5586 49499 -152128 -302859 410632 91238 106253 -85512 -285456 93914 22420 306870 -168538 -250834 134776 440534 25180 -494648 51267 16534 371022 -407391 127338 431943 -117501 -272130 -289809 168147 -243149 -312567 -203441 310804 -74561 -5157 -392990 -408426 385248 237367 -465550 -174147 -453941 288219 165118 107344 -227692 393320 62200 249040 -57068 -245873 -498209 -3775 157111 -142467 327425 -250748 369047 -332614 -6184 410141 -94387 -404 -316372 -78941 -104292 -462631 80469 274213 -437028 -383257 257719 596 -291150 -358098 44982 245542 -66025 -428457 -401975 -54645 185809 29800 -366370 390523 -220774 -169243 291489 184462 -319126 -487795 -268607 -229989 411033 197612 -172566 201498 -339099 208080 -487421 69867 154857 -383783 -98463 179488 32539 384607 3775 -47585 29509 -161411 -483040 -370733 -254556 -318105 -209994 -223195 -331453 -376618 415993 -153694 -252107 273656 150287 139186 -75303 3876 377395 298639 444587 -370064 100567 -273942 297420 -326807 -304711 -190080 -490797 -179603 -14138 457302 369359 -298482 347000 -122963 392299 -246898 390503 141080 -158393 126088 -241497 433913 -298461 -221944 354327 110964 237732 -233127 435315 200066 462908 375190 414959 438687 -12659 -188703 233285 -60282

all:
	$(MAKE) $(NAME)

$(NAME): libft .NotRelink

.NotRelink: $(LIBFT_LIB) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	touch .NotRelink

libft:
	$(MAKE) -C $(LIBFT_DIR)

bonus: libft
	$(MAKE) $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT_LIB) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(LIBFT_LIB) -o $(NAME_BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE_DIR)$(NAME).h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: 
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME) $(NAME_BONUS) .NotRelink

re:
	$(MAKE) fclean
	$(MAKE) all

run:
	$(MAKE)
	./$(NAME) $(ARR)

check:
	$(MAKE)
	./$(NAME) $(ARR) | ./checker_linux $(ARR)

val:
	$(MAKE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./$(NAME) $(ARR)
##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

SRC		= 		./src/main.c 							\
				./src/error.c 							\
				./src/tool.c 							\
				./src/my_ls.c							\
				./src/ls_flag.c 						\
				./src/flag/l_flag.c 					\
				./src/flag/a_flag.c 					\
				./src/flag/r_flag.c 					\
				./src/link/link.c 						\
				./src/link/tool_link.c 					\
				./src/pars_file.c 						\

OBJ		= $(SRC:.c=.o)

CC 		= gcc

RM		= rm -f

NAME	= my_ls

LIB		= make -C ./lib/my

TEST 	= make -C ./tests

CFLAGS	= -W -Wall -Wextra -g3 -I./include/

CSFML	= -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

LDFLAGS		=  -L. lib/libmy.a

all: 		start $(NAME) end

$(NAME):	$(OBJ)
			$(LIB)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	$(LIB)
	gcc -o unit $(FILE_T) $(SRC_TEST) $(UNIT_FLAGS) $(CFLAGS)
	./unit
	gcovr -r . --branches; lcov --capture --directory  ./ --output-file covActi.info --rc lcov_branch_coverage=1 --exclude ./unit

retest:
	$(TEST) re
	./tests/unit_tests

clean:
		$(LIB) clean
		$(RM) $(OBJ)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
		$(RM) $(NAME)
		$(LIB) fclean
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

end:
	@echo "\033[5m\033[1m\033[32mEtat for -> $(NAME) -> compil -> OK\033[0m"

start:
	@echo "\033[5m\033[1m\033[32mWe compil your project\033[0m"

re:		fclean all
##
## EPITECH PROJECT, 2019
## epitech-makefile
## File description:
## Generic Makefile for Epitech
##

SHELL	=	bash

SRC 	=	src/first_player/connect.c		\
			src/first_player/loop.c			\
			src/second_player/connect.c		\
			src/second_player/loop.c		\
			src/game/seek_n_read.c			\
			src/parsing/file_parsing.c		\
			src/parsing/my_split_cpy.c		\
			src/parsing/my_str_split.c		\
		  src/game/defend.c             \
		  src/game/create_map.c         \
		  src/game/attack.c \
		  src/attack_log.c \
		  src/display.c \

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_SRC	=	tests/test_your_test.c	\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror -pedantic -g3

LFLAGS	=	-L./lib -lmy

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET	=	navy

TARGET_TEST	=	yoshida

#-------------------------------------------------------------------------------

all:	$(TARGET) ## Build the main binary with libs

$(TARGET) : build_lib build

build_lib: ## Compile the libs
	@$(MAKE) -C ./lib/my/ --silent
	@cp ./lib/my/libmy.a ./lib/libmy.a
	@cp ./lib/my/my.h ./include/my.h

%.o: %.c ## Compile the objects
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ) ## Build the main binary
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

clean_lib: ## Clean the libs
	@$(MAKE) -C ./lib/my/ --silent clean

fclean_lib: ## Force clean the libs
	@$(MAKE) -C ./lib/my/ --silent fclean
	@rm -f lib/libmy.a

clean: clean_lib ## Clean the project
	@rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(COVERAGE) $(CPPDEPS)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(COVERAGE) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(CPPDEPS) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: fclean_lib clean ## Force clean the project
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all ## Force clean then compile

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LFLAGS) $(TEST_LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLaunching tests...\e[0m]\n"
	@./$(TARGET_TEST)
	@gcovr --exclude tests/

re_tests: fclean tests_run ## Force clean then launch tests

valgrind: all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help valgrind
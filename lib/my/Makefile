##
## EPITECH PROJECT, 2018
## makefile
## File description:
## it makes files
##

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	@echo -e "\033[1;93mCompiling lib....\033[0;39m"
	gcc -W -Wall -Wextra -pedantic -Werror -c *.c
	ar rc $(NAME) *.o
	@echo -e "\033[1;32mLib successfully compiled !\033[0;39m"

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean clean all
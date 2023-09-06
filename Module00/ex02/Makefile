NAME = tests
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
FLG = -Wall -Wextra -Werror -c

$(NAME):
	mkdir obj
	c++ $(SRC) $(FLG)
	c++ $(OBJ) -o $(NAME)
	mv *.o obj

all:	$(NAME)

clean:
	rm -rf obj

fclean:	clean
	rm -rf $(NAME)

re:		fclean all
NAME = violence
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
FLGS = -Wall -Wextra -Werror -std=c++98

$(NAME):
	mkdir obj
	c++ $(SRC) $(FLGS) -c
	c++ $(OBJ) -o $(NAME)
	mv *.o obj

all:	$(NAME)

clean:
	rm -rf obj

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
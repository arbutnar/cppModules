NAME = PmergeMe
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
FLG = -Wextra -Wall -Werror -std=c++98

$(NAME): $(SRC)
	mkdir -p obj
	c++ $(SRC) -c
	c++ $(OBJ) -o $(NAME)
	mv *.o obj

all:	$(NAME)

clean:
	rm -rf obj

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
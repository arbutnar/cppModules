NAME = forms
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
MYFILE = *_shrubbery
FLG = -Wextra -Wall -Werror -std=c++98

$(NAME):
	mkdir obj
	c++ $(SRC) $(FLG) -c
	c++ $(OBJ) -o $(NAME)
	mv *.o obj

all:	$(NAME)

clean:
	rm -rf obj
	rm -rf $(MYFILE)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

NAME	= Game

SRC	= ./src/main.cpp \
	./src/Window.cpp \

OBJ	 = $(SRC:.cpp=.o)

COMPILER = g++
CXXFLAGS = -std=c++17 -I./include


all:	$(NAME)

$(NAME):	$(OBJ)
	$(COMPILER) -o $(NAME) $(CXXFLAGS) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -g3 

clean:
	rm -rf src/*.o

fclean:	clean
	rm -rf $(NAME)
	rm -rf ./*~

re:	fclean all
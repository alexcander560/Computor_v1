.PHONY	:	all clean fclean re

NAME	=	computor_v1

HEADER	=	polynomial.hpp

SRC		=	polynomial.cpp		main.cpp

FLAGS	=	-Wall -Wextra -Werror

OBJ		=	$(patsubst %.cpp, %.o, $(SRC))

all		:	$(NAME)

$(NAME):	$(SRC) $(HEADER)
	clang++ $(FLAGS) -c $(SRC)
	clang++ $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

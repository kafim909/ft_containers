VECTOR_LOG_PATH = /Users/mtournay/Desktop/ft_containers/tests/vector/logs/

VECTOR_TEST =   tests/vector/basic.cpp tests/vector/basicRef.cpp tests/vector/iterators.cpp \
				tests/vector/iteratorsRef.cpp tests/vector/operators.cpp tests/vector/erase.cpp \
				tests/vector/insert.cpp

SRCS		=	main.cpp tests/tests.cpp $(VECTOR_TEST)


OBJS		=	$(SRCS:%.cpp=%.o) 

NAME		=	ft_containers

CC					=	c++
CFLAGS				=	-Wshadow -Wall -Wextra -Werror -fsanitize=address -std=c++98\

all:		$(NAME)

$(NAME):	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
				@rm -f ${OBJS}

fclean:		clean
				@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
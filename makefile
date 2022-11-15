VECTOR_TEST_PATH 	= tests/vector/

VECTOR_TEST_FILES	=   basic.cpp basicRef.cpp iterators.cpp iteratorsRef.cpp operators.cpp erase.cpp insert.cpp relational_ope.cpp size.cpp reverse_it.cpp

VECTOR_TEST			= $(addprefix $(VECTOR_TEST_PATH), $(VECTOR_TEST_FILES))

VECTOR_LOG_PATH 	= /Users/mtournay/Desktop/ft_containers/tests/vector/logs/

VECTOR_LOGS			= $(addprefix $(VECTOR_LOG_PATH), *.txt)


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
				@rm -f $(NAME) @rm -f $(VECTOR_LOGS)

re:			fclean all

.PHONY:		all clean fclean re
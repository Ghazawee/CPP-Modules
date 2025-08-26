NAME = mutantstack

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

DEL = rm -rf

all: $(NAME)

%.o: %.cpp MutantStacl.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(NAME)

re: fclean all
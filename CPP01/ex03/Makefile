NAME = unnecessary_violence

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DEL = rm -rf

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
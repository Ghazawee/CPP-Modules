NAME =  BraiiiiiiinnnzzzZ

SRCS = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
DEL = rm -f

all: $(NAME)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(DEL) $(OBJS)
fclean: clean
	$(DEL) $(NAME)
re: fclean all

.PHONY: all clean fclean re
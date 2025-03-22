NAME = phonebook

SRCS = main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

DEL = rm -f

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
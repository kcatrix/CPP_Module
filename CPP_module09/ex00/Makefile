
CC = g++

RM = rm -f

CFLAGS = -Wall -Wextra  -std=c++98

NAME = btc

DB = data.csv

SRC =  $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

all:
	@$(MAKE) -j $(NAME)	

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	$(CC) -c $(CFLAGS) $(SRC) $< -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(DB)

re: fclean all

.PHONY: all clean fclean re

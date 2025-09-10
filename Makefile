NAME = webserv

SRCDIR = srcs
SOURCES = main.cpp
SRCS = $(addprefix $(SRCDIR)/, $(SOURCES))

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I./includes

RM = rm -f

$(NAME): $(SRCS)
		$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		@echo "Nothing to clean (no object files)"

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
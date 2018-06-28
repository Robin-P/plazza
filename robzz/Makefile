NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp \
	  ./srcs/basics.cpp \
	  ./srcs/font.cpp \
	  ./srcs/printMenuMode.cpp \
	  ./srcs/createWindow.cpp \
	  ./srcs/manageEvents.cpp \
	  ./srcs/ls.cpp \
	  ./srcs/drawText.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I include
CPPFLAGS += -W -Wall -Wextra -g3
LDFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

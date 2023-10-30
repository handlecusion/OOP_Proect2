NAME = prob2.exe
CC = g++
CFLAGS = 
SRCS = main.cpp inf_int.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY : all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

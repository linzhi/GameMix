OUT = snake
CXX = gcc
CXXFLAGS = -Wall -g
OBJS = snake.o

snake.o:snake.c snake.h
	$(CXX) -c $(CXXFLAGS) snake.c

.PHONY:clean

clean:
		rm -f *.o snake

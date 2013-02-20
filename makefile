OUT = GameMix
CXX = gcc
CXXFLAGS = -Wall -g
SUBDIRS = snake
OBJS = main.o engine.o keyinput.o snake/snake.o
LIBS = -lcurses

$(OUT):$(OBJS)
	$(foreach N,$(SUBDIRS),make -C $(N);) \
	$(CXX) -o $(OUT) $(OBJS) $(LIBS)

main.o:main.c keyinput.h engine.h
	$(CXX) -c $(CXXFLAGS) main.c

engine.o:engine.c engine.h
	$(CXX) -c $(CXXFLAGS) engine.c

keyinput.o:keyinput.c keyinput.h
	$(CXX) -c $(CXXFLAGS) keyinput.c

.PHONY:clean

clean:
	-rm -f $(OBJS) GameMix

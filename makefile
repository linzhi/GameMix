GameMix:main.o engine.o keyinput.o snake.o
	gcc -o GameMix main.o engine.o keyinput.o snake.o -lcurses

main.o:main.c keyinput.h engine.h
	gcc -c main.c

engine.o:engine.c engine.h
	gcc -c engine.c -lcurses

keyinput.o:keyinput.c keyinput.h
	gcc -c keyinput.c -lcurses

snake.o:snake.c snake.h
	gcc -c snake.c -lcurses

.PHONY:clean
clean:
	-rm main.o engine.o keyinput.o snake.o

CFLAGS = -g --std=c++11

all: main

main: main.o lexer.o State.o symbole.o automate.o
	g++ $(CFLAGS) -o main *.o

lexer.o: lexer.cpp lexer.h
	g++ $(CFLAGS) -c lexer.cpp

State.o: State.cpp State.h
	g++ $(CFLAGS) -c State.cpp

symbole.o: symbole.cpp symbole.h
	g++ $(CFLAGS) -c symbole.cpp

automate.o: automate.cpp automate.h State.h symbole.h
	g++ $(CFLAGS) -c automate.cpp

clean:
	rm -f *.o main


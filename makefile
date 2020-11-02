FLAGS = -pedantic-errors -std=c++11

mainfile.o:mainfile.cpp
	g++ $(FLAGS) -c $<

choices.o: choices.cpp
	g++ $(FLAGS) -c $<

ask.o: ask.cpp
	g++ $(FLAGS) -c $<

randgame.o: randgame.cpp
	g++ $(FLAGS) -c $<

main: main.cpp randgame.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o

.PHONY: clean

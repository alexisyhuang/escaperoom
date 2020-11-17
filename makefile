FLAGS = -pedantic-errors -std=c++11

chatbot.o: chatbot.cpp structure.h chatbot.h
	g++ $(FLAGS) -c $<

fakemain.o: fakemain.cpp chatbot.cpp structure.h chatbot.h
	g++ $(FLAGS) -c $<

main.o: main.cpp chatbot.cpp structure.h chatbot.h
	g++ $(FLAGS) -c $<

fakemain: fakemain.o chatbot.o
	g++ $(FLAGS) $^ -o $@

main: main.o chatbot.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o

.PHONY: clean

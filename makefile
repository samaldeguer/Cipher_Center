exec: main.o Operations.o Executive.o
	g++ -std=c++11 -Wall -g main.o Operations.o Executive.o -o exec

main.o: main.cpp Operations.h Executive.h
	g++ -std=c++11 -Wall -g -c main.cpp

Operations.o: Operations.h Operations.cpp
	g++ -std=c++11 -Wall -g -c Operations.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -Wall -g -c Executive.cpp

clean:
	rm *.o exec

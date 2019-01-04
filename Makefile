CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

test : main.o game.o
	${CXX} ${CXXFLAGS} ${LDLFLAGS} -o test main.o game.o

main.o : main.cpp
game.o : game.cpp

clean :
	rm -f *.o
	rm test

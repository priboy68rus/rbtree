CFLAGS = -g -Wall -fprofile-arcs -ftest-coverage

all: main.cpp
	g++ ${CFLAGS} -o main main.cpp
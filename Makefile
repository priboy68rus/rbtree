all: main.o rbtree.o
	g++ -o main main.o rbtree.o

main.o: main.cpp
	g++ -c main.cpp

rbtree.o:
	g++ -c rbtree.cpp
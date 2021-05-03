all: compile run

compile:
	gcc -I ./include -o ./lib/Node.o -c ./src/Node.c
	gcc -I ./include -o ./lib/LinkedList.o -c ./src/LinkedList.c
	gcc -I ./include -o ./bin/Program ./lib/Node.o ./lib/LinkedList.o ./src/Program.c

run:
	./bin/Program
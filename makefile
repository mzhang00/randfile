all: randfile.o
	gcc -o program randfile.o

randfile.o: randfile.c
	gcc -o randfile.c

run:
	./program
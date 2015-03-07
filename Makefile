CC=gcc
CFLAGS= -Wall -g

build:
	make mymalloc.o main.o test

test: mymalloc.o main.o
	$(CC) $(CFLAGS) mymalloc.o main.o -o test

mymalloc.o: mymalloc.c mymalloc.h
	$(CC) $(CFLAGS) -c mymalloc.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	-rm *.o 
	-rm test

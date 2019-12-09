ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	$(CC) -o output main.o

main.o: main.c main.h
	$(CC) -c main.c

run:
	./output

memcheck:
	valgrind --leak-check=yes ./output

clean:
	rm *.o

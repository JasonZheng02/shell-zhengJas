ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: shell.o
	$(CC) -o output shell.o

main.o: shell.c shell.h
	$(CC) -c shell.c

run:
	./output

memcheck:
	valgrind --leak-check=yes ./output

clean:
	rm *.o

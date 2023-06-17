CFLAGS = -Wall -g

all: myht

myht: myht.o hash.o
	gcc -o myht myht.o hash.o

myht.o: myht.c
	gcc -c myht.c $(CFLAGS)

hash.o: hash.c hash.h
	gcc -c hash.c $(CFLAGS)

clean:
	-rm *.o

purge:
	-rm *.o myht
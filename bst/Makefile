# Makefile
#

CC=gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: btTraversal

btTraversal: btTraversal.o BSTree.o Queue.o LList.o
	$(CC) $(LDFLAGS) $^ -o $@

btTraversal.o: btTraversal.c BSTree.h
	$(CC) -c $(CFLAGS) $< -o $@

BSTree.o: BSTree.c BSTree.h Queue.h
	$(CC) -c $(CFLAGS) $< -o $@

Queue.o: Queue.c Queue.h LList.h
	$(CC) -c $(CFLAGS) $< -o $@

LList.o: LList.c LList.h
	$(CC) -c $(CFLAGS) $< -o $@



.PHONY: clean 

clean:
	rm -rf *.o
	rm -rf btTraversal
	

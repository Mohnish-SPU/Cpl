# Makefile
#

CC=gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: token

token: token.o BSTree.o Queue.o LList.o
	$(CC) $(LDFLAGS) $^ -o $@

token.o: token.c BSTree.h
	$(CC) -c $(CFLAGS) $< -o $@

BSTree.o: BSTree.c BSTree.h Queue.h
	$(CC) -c $(CFLAGS) $< -o $@

Queue.o: Queue.c Queue.h LList.h
	$(CC) -c $(CFLAGS) $< -o $@

LList.o: LList.c LList.h
	$(CC) -c $(CFLAGS) $< -o $@



.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf token
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

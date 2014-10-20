# Makefile
#

SH = bash
CFLAGS = -g

all: main

main: main.o
	gcc $^ -o $@
	
main.o: main.c
	gcc -c $(CFLAGS) $< -o $@
	
.PHONY: clean

clean:
	rm -rf *.o
	rm -rf main


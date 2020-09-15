#
# Makefile
#

all : menu.o main.c stat.o
	gcc -Wall main.c menu.o

menu.o : menu.h menu.c
	gcc -Wall -c menu.c 

stat.o : stat.c stat.h
	gcc -Wall -c stat.c

clean: 
	rm -f a.out *.o 
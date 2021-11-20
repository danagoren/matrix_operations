mymat : mymat.o mat.o
	gcc -g -Wall -ansi -pedantic mymat.o mat.o -o mymat
mymat.o : mymat.c
	gcc -c -Wall -ansi -pedantic mymat.c -o mymat.o
mat.o : mat.c
	gcc -c -Wall -ansi -pedantic mat.c -o mat.o

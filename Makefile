
execute: main.o
		gcc -Wall -Werror -pedantic -o execute main.o

main.o: main.c functionsFS.h
		gcc -Wall -Werror -pedantic -c main.c

clean:
		rm -f execute *.o	
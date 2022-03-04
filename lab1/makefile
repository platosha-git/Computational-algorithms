all: app.exe
app.exe: main.o io_handler.o calculations.o
	gcc -o app.exe main.o io_handler.o calculations.o

app.out: main.o
	gcc -o app.out main.o io_handler.o calculations.o

main.o: main.c io_handler.h calculations.h constants.h
	gcc -std=c99 -Wall -Werror -c -pedantic main.c -lm

io_handler.o: io_handler.c io_handler.h constants.h
	gcc -std=c99 -Wall -Werror -pedantic -c io_handler.c -lm

calculations.o: calculations.c calculations.h constants.h
	gcc -std=c99 -Wall -Werror -pedantic -c calculations.c -lm

clean:
	rm *.o*.exe

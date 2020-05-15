CFLAGS = -Wall -g

exec : src/main.o src/song.o
	clang src/main.o src/song.o -o exec

src/main.o : src/main.c
	clang src/main.c -Iinclude $(CFLAGS) -c -o src/main.o

src/song.o : src/song.c
	clang src/song.c -Iinclude $(CFLAGS) -c -o src/song.o

clean :
	rm src/*.o exec

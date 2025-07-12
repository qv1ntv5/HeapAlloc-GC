CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic -ggdb

libheapalloc.so: heap.c heap.h
	gcc -shared -fPIC -o libheapalloc.so heap.c heap.h

heap: main.c libheapalloc.so
	gcc $(CFLAGS) -o heap main.c libheapalloc.so


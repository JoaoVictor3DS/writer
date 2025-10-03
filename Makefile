CC=clang
CFLAGS=-Wall -Werror -Wpedantic -g

all: ./bin/writer

./bin/writer: ./build/writer.o
	${CC} $^ -o $@ ${CFLAGS}

./build/writer.o: ./src/writer.c
	${CC} -c $^ -o $@ ${CFLAGS}

clean:
	rm -rf bin/* build/*

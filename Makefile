BINDIR := ./bin
OBJDIR := ./obj
SRCDIR := ./src
LIBDIR := ./lib
INCDIR := ./include
TESTDIR := ./test

CC := clang
LDFLAGS := -L./lib 
CFLAGS := -I$(INCDIR) -Wall -Wextra -Wpedantic -Wconversion -Werror -g3 -std=c17 -fsanitize=address -fsanitize=undefined -fsanitize-trap
SRC := $(wildcard ${SRCDIR}/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

PROJ := ${BINDIR}/writer

all: ${PROJ}

${PROJ}: ${OBJ}
	${CC} $^ -o $@ ${CFLAGS} ${LDFLAGS}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	${CC} -c $< -o $@ ${CFLAGS}

clean:
	rm -rf ${OBJDIR}/* ${BINDIR}/*

test: ${PROJ}

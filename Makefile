BINDIR := ./bin
OBJDIR := ./obj
SRCDIR := ./src
LIBDIR := ./lib
INCDIR := ./include
TESTDIR := ./test

CC := clang
CFLAGS := -I$(INCDIR) -Wall -Wextra -Wpedantic -Wconversion -Werror \
          -g3 -std=c17 -fsanitize=address -fsanitize=undefined -fsanitize-trap
LDFLAGS := -L$(LIBDIR)

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
PROJ := $(BINDIR)/writer
TESTSRC := $(wildcard $(TESTDIR)/test_*.c)

all: $(PROJ)

$(PROJ): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
	@echo "Build done: $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

test: $(TESTSRC)
	@mkdir -p $(BINDIR)
	@for t in $^; do \
		testbin=$(BINDIR)/$$(basename $$t .c); \
		echo "Compiling and executing $$t -> $$testbin"; \
		echo ""; \
		$(CC) $$t $(filter-out $(SRCDIR)/main.c,$(SRC)) -o $$testbin $(CFLAGS) $(LDFLAGS); \
		$$testbin; \
	done

clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*
	@echo "Project Cleanned!"

.PHONY: all clean test

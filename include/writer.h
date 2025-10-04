#ifndef WRITER_H
#define WRITER_H

#include <stdio.h>

FILE *get_file(const char *filename);

int print_file(FILE *fp);

#endif

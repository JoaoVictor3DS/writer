#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_ERROR 1
#define FILE_SUCCESS 0

FILE *get_file(const char *filename) {
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    return NULL;
  }

  return fp;
}

int print_file(FILE *fp) {
  if (fp == NULL) {
    printf("Invalid file pointer\n");
    return FILE_ERROR;
  }

  int c = 0;
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  return FILE_SUCCESS;
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int print_file(const char *filename) {
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  int c = 0;
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  fclose(fp);

  return 0;
}

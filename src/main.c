#include <stdio.h>

#include <writer.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Provide at least one file\n");
    return 1;
  }

  const char *filename = argv[1];

  print_file(filename);

  return 0;
}

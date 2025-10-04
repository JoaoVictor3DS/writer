#include <stdio.h>

#include <writer.h>

int main(const int argc, const char **argv) {
  if (argc < 2) {
    printf("Provide at least one file\n");
    return 1;
  }

  const char *filename = argv[1];

  FILE *fp = get_file(filename);

  print_file(fp);

  return 0;
}

#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Provide at least one file");
    return 1;
  }
  printf("%s\n", argv[1]);
}

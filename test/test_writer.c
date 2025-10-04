#include "cest.h"
#include <stdio.h>
#include <writer.h>

const char *true_filename = "test/samples/sample.txt";
const char *false_filename = "false_file";

int main(void) {
  int status_code;

  FILE *f_ok = NULL;
  FILE *f_fail = NULL;

  // --- 1 Test get_file() ---

  // Success
  f_ok = get_file(true_filename);
  ASSERT_TRUE(f_ok, "Open valid file");

  // Failure
  f_fail = get_file(false_filename);
  ASSERT_FALSE(f_fail, "Fail on invalid file");

  // --- 2 Test print_file() ---

  // Success
  status_code = print_file(f_ok);
  ASSERT_SUCCESS(status_code, "Handle valid file");

  // Failure
  status_code = print_file(f_fail);
  ASSERT_FAILURE(status_code, "Reject invalid file");

  if (f_ok) {
    fclose(f_ok);
  }

  TEST_SUMMARY();

  return 0;
}

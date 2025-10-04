#ifndef CEST_H
#define CEST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

static int tests_run = 0;
static int tests_failed = 0;
static int tests_warning = 0;

static inline void log_pass(const char *msg, const char *file) {
  printf(GREEN "[PASS] %s: %s\n" RESET, file, msg);
}

static inline void log_fail(const char *msg, const char *file, int line) {
  printf(RED "[FAIL] %s:%d: %s\n" RESET, file, line, msg);
}

static inline void log_warning(const char *msg) {
  printf(YELLOW "[WARN] %s\n" RESET, msg);
}

#define ASSERT_TRUE(cond, msg)                                                 \
  do {                                                                         \
    tests_run++;                                                               \
    if (!(cond)) {                                                             \
      tests_failed++;                                                          \
      log_fail(msg, __FILE__, __LINE__);                                       \
    } else {                                                                   \
      log_pass(msg, __FILE__);                                                 \
    }                                                                          \
  } while (0)

#define ASSERT_FALSE(cond, msg)                                                \
  do {                                                                         \
    tests_run++;                                                               \
    if ((cond)) {                                                              \
      tests_failed++;                                                          \
      log_fail(msg, __FILE__, __LINE__);                                       \
    } else {                                                                   \
      log_pass(msg, __FILE__);                                                 \
    }                                                                          \
  } while (0)

#define ASSERT_SUCCESS(func_call, msg)                                         \
  do {                                                                         \
    tests_run++;                                                               \
    if (func_call) {                                                           \
      tests_failed++;                                                          \
      log_fail(msg, __FILE__, __LINE__);                                       \
    } else {                                                                   \
      log_pass(msg, __FILE__);                                                 \
    }                                                                          \
  } while (0)

#define ASSERT_FAILURE(func_call, msg)                                         \
  do {                                                                         \
    tests_run++;                                                               \
    if (!func_call) {                                                          \
      tests_failed++;                                                          \
      log_fail(msg, __FILE__, __LINE__);                                       \
    } else {                                                                   \
      log_pass(msg, __FILE__);                                                 \
    }                                                                          \
  } while (0)

#define TEST_WARNING(msg)                                                      \
  do {                                                                         \
    tests_warning++;                                                           \
    log_warning(msg);                                                          \
  } while (0)

#define TEST_SUMMARY()                                                         \
  do {                                                                         \
    printf("\n--- Test Summary ---\n");                                        \
    printf("Run: %d | Failed: %d | Warnings: %d | Passed: %d\n", tests_run,    \
           tests_failed, tests_warning, tests_run - tests_failed);             \
    if (tests_failed > 0)                                                      \
      exit(EXIT_FAILURE);                                                      \
  } while (0)

#endif

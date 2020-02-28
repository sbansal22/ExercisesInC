#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "util.h"

int tests_run = 0;

static char *test_icmpcode_v4() {
    char *res = icmpcode_v4(15);
    char *message = "test failed!";
    mu_assert(message, strcmp(res, "precedence cutoff in effect") == 0);
    return NULL;
}

static char *all_tests() {
  mu_run_test(test_icmpcode_v4);
  return NULL;
}

int main(int argc, char ** argv){
  char *result = all_tests();
  if (result != NULL){
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}

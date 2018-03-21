#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "carp_string.h"

String Env_getenv(String *var) {
  char* x = getenv(*var);
  char* empty = "";
  if (x == NULL) return String_str(&empty);
  return String_str(&x);
}


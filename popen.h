#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "carp_string.h"

String Popen_popen(String *cmd) {
  FILE *fp;
  char path[100];
  String buffer = NULL;
  String temp = NULL;
  unsigned int size = 1;  // start with size of 1 to make room for null terminator
  unsigned int strlength;

  /* Open the command for reading. */
  fp = popen(*cmd, "r");
  if (fp == NULL) {
    printf("Failed to run command\n");
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    strlength = strlen(path);
    temp = realloc(buffer, size + strlength);  // allocate room for the buf that gets appended
    if (temp == NULL) {
      // allocation error
    } else {
      buffer = temp;
    }
    strcpy(buffer + size - 1, path);     // append buffer to str
    size += strlength;
  }

  /* close */
  pclose(fp);

  return buffer;
}
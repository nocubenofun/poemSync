/* This is the process library of poemSync. Licensed under MIT/X license. */
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "config.h"

void run_child(char* efn) {
  /* This function fork a child and then execute file in "efn" in this child. Will print some debug message if RELEASE is not defined. */
#ifndef RELEASE
  printf("Enter function: int run_child(char* efn) in poemprocess.c");
#endif
  int cld=fork();
#ifndef RELEASE
  printf("Forked!");
#endif
  switch (cld) {
    /* Judge if this is child or father. */
    case 0:
#ifndef RELEASE
      printf("Running execv...");
#endif
      execv(efn, NULL);
      break;
    case -1:
#ifndef RELEASE
      printf("DEBUG ERROR: fork returns -1. at run_child function.");
#endif
      perror("Process initialization failed. Kernel process tree resource busy.");
      break;
    default:
#ifndef RELEASE
      printf("Parent Process done run_child.");
#endif
      break;
  }
}

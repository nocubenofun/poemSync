/* This is the "start" of poemSync. This file and other files IN MAIN UNIT(/builddir/src) is licensed under MIT/X license. */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include "poemprocess.h"
#include "config.h"
#include "ini.h"

void sinitlcl() {
  /* System initialization from local config file. */
  char buffer[128]; //Buffer to read dir from config file.
  int rslt; //Result of succeed or not.
  rslt=GetIniKeyString("pldload", "ldlstfn", MCONFIG_FILE, buffer);
  switch (rslt) {
    case -1:
#ifndef RELEASE
      printf("! DEBUG: Read pldload.ldlstfn Failed!!!");
      perror("! INIT FAILED!!! Exiting...");
      exit(1);
      return;
#endif
      printf("! INIT FAILED!!! Failed to sync MCONFIG_FILE!!!");
      printf("! Entering Emergency Shell...");
      system("/bin/sh");
      return;
      break;
    default:
      printf("Reading pldload.ldlstfn...");
      break;
  }
  char mntldbfr[128]; //Buffer to mount module
  rslt=GetIniKeyString("main", "mount.mod", buffer, mntldbfr);
  switch (rslt) {
    case -1:
#ifndef RELEASE
      printf("! DEBUG: Read main.mount.mod Failed!!!");
      perror("! INIT FAILED!!! Exiting...");
      exit(1);
      return;
#endif
      printf("! INIT Warning! Mount.mod not found here. Initialization will continue, but may have troubles.");
      goto nrcmcntn;
      break;
    default:
      printf("Spawning MOUNT MOD...");
      break;
  }
  run_child(mntldbfr);
  nrcmcntn:
  printf("[poemSync] Self-syncing done.");
  printf("[poemSync] Syncing poemSync main directory...");
  system("/bin/clear");
  char bfr_svcsrvr[128];
  GetIniKeyString("main", "svcsrvr.mod", buffer, bfr_svcsrvr);
  run_child(bfr_svcsrvr);
}
void sysinit() {
  /* System Initialization Function. */
  printf("poemSync - opening core module...");
  if (MCONFIG_FILE == "_REMOTE_") {
    /* Mount remote */
  } else {
    /* Read local config file */
    sinitlcl();
  }
}
void init_cmdline() {
  /* init 0-6 */
}
int main() {
  /* Initialization of system startup */
  if (getpid() != 1) {
    /* Check if PID=1. If not, judge command line. And then do something. */
    init_cmdline();
  } else {
    /* System Initialization */
    sysinit();
  }
  while (true) {
    /* Do nothing */
  }
}

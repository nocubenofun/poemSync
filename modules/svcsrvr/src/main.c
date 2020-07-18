/* POEMSYNC SERVICE MANAGING DAEMON. LICENSED UNDER 3-clause BSD LICENSE; AS A PART OF POEMSYNC BUT HAVE A DIFFERENT LICENSE. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "config.h"
#include "ini.h"
#include "poemprocess.h"

int main() {
  /* First, load core services. */
  char csvcd[] = POEMSYNC_MD;
  strcat(csvcd, "/coresvc");
  strcat(csvcd, "/run.sh");
  system(csvcd);
  /* Then load single-user services. */
  char susvcd[] = POEMSYNC_MD;
  strcat(susvcd, "/single-user/run.sh");
  run_child(susvcd);
  /* Then load multi-user services. */
  char musvcd[] = POEMSYNC_MD;
  strcat(musvcd, "/multi-user/run.sh");
  run_child(musvcd);
  /* Then load getty services. */
  char gtsvcd[] = POEMSYNC_MD;
  strcat(gtsvcd, "/tty/run.sh");
  run_child(gtsvcd);
  /* Read config for delay services. */
  char delayusec[128]; //Delay time(usecond)
  char dsvcd[] = POEMSYNC_MD;
  strcat(dsvcd, "/delay.ini")
  GetIniKeyString("delay", "time", dsvcd, delayusec);
  int dusec = asoi(delayusec);
  sleep(dusec);
  char dsvcd2[] = POEMSYNC_MD;
  strcat(dsvcd2, "/delay/run.sh");
  run_child(dsvcd2);
  while(true) {
    sleep(10000);
  }
}

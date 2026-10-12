#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t berhenti = 0;
void Sinyal(int sig) { berhenti = 1; }

int main(void) {
  signal(SIGINT, Sinyal);

  while (berhenti == 0) {
    printf("pid program %d\n", getpid());
  }

  printf("program selesai dengan kode %d\n",(int)berhenti);

  return 0;
}

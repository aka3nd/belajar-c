// belajar signal pause()

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t berhenti = 0;

void Sinyal(int a) { berhenti = a; }

int main(void) {

  signal(SIGINT, Sinyal); // interup sigint
  printf("menunggu sinyal... pid %d\n",getpid());
  pause();
  printf("sinyal dijalakan dengan nomor signal %d\n", berhenti);

  return 0;
}

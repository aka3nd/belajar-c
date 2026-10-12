#include <stdio.h>
#include <unistd.h>
#include <signal.h>
volatile sig_atomic_t berhenti = 0;

void notifikasi(int a){
  berhenti = a;
}

int main(void)
{
  signal(SIGINT,notifikasi);
  signal(SIGUSR1,notifikasi);

  while(berhenti == 0){
    printf("program sedang berjalan dengan pid: %d\n",getpid());
    sleep(1);
  }

  printf("nomor signal yang digunakan %ld\n",berhenti);
  return 0;
}

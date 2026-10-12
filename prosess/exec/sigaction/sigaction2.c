#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;

void Message(int sig) { stop = sig; }

int main(void) {
  struct sigaction aksi;
  aksi.sa_handler = Message;
  sigemptyset(&aksi.sa_mask);
  aksi.sa_flags=0;

  sigaction(SIGINT,&aksi,NULL);

  while(stop == 0){
    printf("proses berjalan dengan PID: %d\n",getpid());
    sleep(1);
  }
  printf("signal berhenti\n");
  printf("kode nomor signal %d\n",(int)stop);
  return 0;
}

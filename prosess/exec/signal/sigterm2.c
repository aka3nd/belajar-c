#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void Notif(int message) { printf("kode sigterm %d\n", message); }

int main(void){
  signal(SIGTERM,Notif);

  printf("nomor pid saya %d\n",getpid());
  printf("menunggu signal sigterm\n");

  while(1){
    pause();
  }

  return 0;
}

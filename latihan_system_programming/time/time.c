#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  while (1) {
    time_t waktu = time(NULL);
    if (waktu == -1) {
      perror("time gagal");
      return 1;
    }
    struct tm *waktu_lokal = localtime(&waktu);
    if (waktu_lokal == NULL) {
      fprintf(stderr, "localtime gagal");
      return 1;
    }

    char buff[100];
    size_t panjang = strftime(buff, sizeof(buff), "%H:%M:%S", waktu_lokal);

    if (panjang == 0) {
      perror("panjang error");
      return 1;
    }

    printf("\rJam: %s", buff);
    fflush(stdout);
  }
  return 0;
}

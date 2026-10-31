#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {

  while (1) {
    time_t sekarang = time(NULL);
    if (sekarang == -1) {
      fprintf(stderr, "waktu error");
      return 1;
    }
    const struct tm *local_time = localtime(&sekarang);

    if (local_time == NULL) {
      fprintf(stderr, "localtime tidak diketahui");
      return 1;
    }
    char buff[20];
    size_t panjang = strftime(buff, sizeof(buff), "%H:%M:%S", local_time);

    if (panjang == 0) {
      fprintf(stderr, "string time error");
      return 1;
    }

    printf("\rjam: %s", buff);
    fflush(stdout);
  }
  return 0;
}

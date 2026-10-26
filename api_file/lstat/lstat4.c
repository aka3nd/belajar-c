#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct stat info;
  struct tm *waktu;
  char tanggal[40];

  if (argc != 2) {
    perror("argv error");
    return 1;
  }

  if (stat(argv[1], &info) == -1) {
    perror("argv error");
    return 1;
  }

  waktu = localtime(&info.st_atim.tv_sec);

  if (waktu == NULL) {
    fprintf(stderr, "waktu error \n");
    return 1;
  }

  if (strftime(tanggal, sizeof(tanggal), "%d-%m-%Y %H:%M:%S", waktu) == 0) {
    fprintf(stderr, "Gagal memformat tanggal\n");
    return 1;
  }

  printf("terakhir diubah: %s\n",tanggal);

  return 0;
}

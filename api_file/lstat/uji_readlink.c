#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char target[10];
  ssize_t panjang;

  if (argc != 2) {
    perror("argv error");
    return 1;
  }

  panjang = readlink(argv[1], target, sizeof(target) - 1);

  if (panjang == -1) {
    perror("panjang gagal");
    return 1;
  }

  target[panjang] = '\0';

  printf("Jumlah byte: %zd\n", panjang);
  printf("Target: %s\n", target);
  return 0;
}

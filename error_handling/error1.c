#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

int main(void) {
  struct stat info;

  if (lstat("tidak_ada.txt", &info) == -1) {
    printf("Kode error: %d\n", errno);
    return 1;
  }

  return 0;
}

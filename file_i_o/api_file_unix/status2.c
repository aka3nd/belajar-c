#include <stdio.h>
#include <sys/stat.h>

int main(void) {
  struct stat info;
  const char *nama = "tautan.txt";

  if (stat(nama, &info) == -1) {
    perror("stat error");
    return 1;
  }
  if(S_ISREG(info.st_mode))pri
  return 0;
}

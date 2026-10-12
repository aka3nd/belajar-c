// stat membaca status file di directory

#include <stdio.h>
#include <sys/stat.h>

int main(void) {
  struct stat info;

  if (stat("stat1.c", &info) == -1) {
    perror("stat error");
    return 1;
  }
  printf("ukuran file: %lld byte\n", (long long)info.st_size);
  printf("Hak akses   : %o\n", (unsigned int)(info.st_mode & 0777));

  return 0;
}

#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
  struct stat info;

  if (argc != 2) {
    perror("agumen gagal");
    return 1;
  }
  if (stat(argv[1], &info) == -1) {
    perror("argv gagal");
    return 1;
  }

  printf("ukuran berkas: %ld byte\n", (long)info.st_size);

  if (S_ISREG(info.st_mode)) {
    printf("jenis: Berkas biasa\n");
  } else if (S_ISDIR(info.st_mode)) {
    printf("jenis: Directory\n");
  } else {
    printf("jenis: lainnya\n");
  }
  return 0;
}

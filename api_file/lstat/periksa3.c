#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat info;

  if (argc != 2) {
    perror("argc errr");
    return 1;
  }
  if (lstat(argv[1], &info) == -1) {
    perror("lstat error");
    return 1;
  }

  if (S_ISLNK(info.st_mode)) {
    printf("Jenis: Symbolic link\n");
  } else if (S_ISREG(info.st_mode)) {
    printf("Jenis: Berkas biasa\n");
  } else if (S_ISDIR(info.st_mode)) {
    printf("Jenis: Directory\n");
  } else {
    printf("jenis lainnya\n");
  }
  return 0;
}

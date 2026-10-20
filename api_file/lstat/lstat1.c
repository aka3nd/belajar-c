#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat info;
  if (argc != 2) {
    fprintf(stderr, "penggunaa %s nama file\n", argv[0]);
    return 1;
  }

  if (lstat(argv[1], &info) == -1) {
    perror("stat error");
    return 1;
  }

  if (S_ISREG(info.st_mode)) {
    printf("file biasa\n");
  } else if (S_ISDIR(info.st_mode)) {
    printf("jenis: directory\n");
  } else if (S_ISLNK(info.st_mode)) {
    printf("jenis: symbolic link\n");
  } else {
    printf("jenis: type lainnya\n");
  }
  return 0;
}

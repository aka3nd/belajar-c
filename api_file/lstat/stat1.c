#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat info;
  if (argc != 2) {
    fprintf(stderr,"argc error");
    return 1;
  }

  if (stat(argv[1], &info) == -1) {
    perror("stat eror");
    return 1;
  }

  printf("ukuran: %lld byte\n", (long long)info.st_size);
  printf("Jumlah hard link: %llu\n", (unsigned long long)info.st_nlink);

  if (S_ISREG(info.st_mode)) {
    printf("Jenis: berkas biasa\n");
  } else if (S_ISDIR(info.st_mode)) {
    printf("Jenis: directory\n");
  } else if (S_ISLNK(info.st_mode)) {
    printf("Jenis: syblix link");
  } else {
    printf("jenis lainnya");
  }
  return 0;
}

#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
  struct stat info;

  if (argc != 2) {
    printf("Penggunaan: %s <path>\n", argv[0]);
    return 1;
  }

  if (stat(argv[1], &info) == -1) {
    perror("stat gagal");
    return 1;
  }

  if (S_ISREG(info.st_mode)) {
    printf("jenis: Berkas biasa\n");
  } else if (S_ISDIR(info.st_mode)) {
    printf("jenis: Directory\n");
  }else if(S_ISCHR(info.st_mode)){
    printf("jenis: char\n");
  }else if(S_ISBLK(info.st_mode)){
    printf("jenis: block\n");
  }else{
    printf("jenis: lainnya\n");
  }
  printf("Izin: %o\n", (unsigned int)(info.st_mode & 0777));

  printf("Ukuran: %lld byte\n", (long long)info.st_size);
  return 0;
}

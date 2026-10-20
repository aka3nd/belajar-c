#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  struct stat info;
  if (argc != 2) {
    printf("Penggunaan: %s <path>\n", argv[0]);
    return 1;
  }

  if(stat(argv[1],&info) == -1){
    perror("stat gagal");
    return 1;
  }
  printf("ukuran: %lld byte\n",(long long)info.st_size);
  printf("Hak akses: %o\n",(unsigned int)info.st_mode & 0777);
  return 0;
}

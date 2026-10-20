#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  struct stat info;

  if(argc != 2){
    fprintf(stderr,"error %s file\n",argv[0]);
    return 1;
  }
  if(stat(argv[1],&info) == -1){
    perror("stat error");
    return 1;
  }
  // int hasil = S_ISREG(info.st_mode);
  // printf("%d\n",hasil);
  int directory = S_ISDIR(info.st_mode);
  printf("%d\n",directory);
  return 0;
}

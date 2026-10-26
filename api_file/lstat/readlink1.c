#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  
  char target[1024];
  ssize_t panjang = readlink("tautan.txt",target,sizeof(target)-1);

  if(panjang == -1){
    perror("panjang error");
    return 1;
  }
  target[panjang] = '\0';
  printf("%s\n",target);
  return 0;
}

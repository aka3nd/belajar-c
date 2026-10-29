#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int input_data;
  int *data;

  printf("masukan data yang ingin dinput? ");
  scanf("%d",&input_data);

  data = malloc(input_data * sizeof(input_data));

  if(data == NULL){
    perror("malloc gagal");
    return 1;
  }
  
  for(int i = 0;i < input_data;i++){
    printf("masukan data ke-%d :",i+1);
    scanf("%d",&data[i]);
  }
  for(int i = 0;i < input_data;i++){
    printf("data ke index %d : %d\n",i,data[i]);
  }

  free(data);
  return 0;
}

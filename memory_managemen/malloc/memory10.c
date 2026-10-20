#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int input_data;
  int *ptr;

  printf("masukan data yang ingin diinput: ");
  scanf("%d",&input_data);

  ptr = malloc(input_data * sizeof(int));

  if(ptr == NULL){
    perror("malloc gagal");
    return 1;
  }

  for(int i = 0;i< input_data;i++){
    printf("input data ke %d = ",i + 1);
    scanf("%d",&ptr[i]);
  }

  for(int i = 0;i< input_data;i++){
    printf("data ke %d = %d\n",i + 1,ptr[i]);
  }

  printf("%d\n",*(ptr+1));

  free(ptr);
  return 0;
}

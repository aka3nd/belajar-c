#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int input_data;
  int *ptr;
  printf("berapa input data yang ingin dibuat: ");
  scanf("%d", &input_data);
  int *data = malloc(input_data * sizeof(int));

  if(data == NULL){
    return 1;
  }
  ptr = data;

  for (int i = 0; i < input_data; i++) {
    printf("input data: %d ",i+1);
    scanf("%d", &data[i]);
  }
  printf("data yang diinputkan\n");
  for(int i=0;i<input_data;i++){
    printf("data ke %d = %d\n",i+1 ,*(data + i));
  }

  //memajukan pointer
  int geser_pointer;
  printf("geser pointer: ");
  scanf("%d",&geser_pointer);

  if(geser_pointer == 1){
    ptr++;
  }else {
  printf("salah input\n");
  }
  printf("data pertama sesudah dimajukan pointer: %d",*ptr);

  free(data);
  data = NULL;
  return 0;
}

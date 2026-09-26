#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  char nama[50];
  int usia;

  struct Node *next;
}Node;

void tambah_data(Node **head,char *nama,int usia){
  Node *next_data = malloc(sizeof(Node));
  if(next_data == NULL){
    return;
  }
  strcpy(next_data->nama,nama);
  next_data->usia=usia;
  next_data->next=*head;
  *head=next_data;
}

int main(void){
  Node *head=NULL;

  tambah_data(&head,"udin",22);
  tambah_data(&head,"didin",26);

  Node *tampil_data = head;
 while (tampil_data !=NULL) {
   printf("nama: %s\n",tampil_data->nama);
   printf("usia: %d\n",tampil_data->usia);

   tampil_data= tampil_data->next;
 
 } 

  return 0;
}

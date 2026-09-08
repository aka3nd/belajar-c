#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int hitung;
  int *p;
  printf("masukan data angka yang diinput: ");
  scanf("%d", &hitung);
  p = malloc(hitung * sizeof(int));
  if (p == NULL) {
    printf("malloc error");
    return 1;
  }

  for (int i = 0; i < hitung; i++) {
    printf("data ke: %d = ", i + 1);
    scanf("%d", &p[i]);
  }

  for(int i = 0;i<hitung;i++){
    printf("data ke: %d\n",p[i]);
  }

  free(p);
  return 0;
}

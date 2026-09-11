#include <stdio.h>
int main(void) {
  int angka;
data:
  printf("masukan angka: dari 1-4: ");
  scanf("%d", &angka);

  switch (angka) {
  case 1:
    printf("ini angka 1");
    break;
  case 2:
    printf("ini angka 2");
    break;
  case 3:
    printf("ini angka 3");
    break;
  case 4:
    printf("ini angka 4");
    break;
  }

  if ((angka > 5 || angka < 1)) {
    printf("bukan angka yang ditentukan\n");
    goto data;
  }
  return 0;
}

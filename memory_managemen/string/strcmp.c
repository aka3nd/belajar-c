#include <stdio.h>
#include <string.h>
int main(void) {
  // strcmp() = membandingkan dua string;
  char nama[] = "dadang";
  char npc[] = "dadang";

  int pembanding = strcmp(nama, npc);
  printf("%d\n", pembanding);
  
  char satu[] = "dadang";
  char dua[] = "tatang";

  int pembanding1 = strcmp(satu,dua);
  printf("%d\n", pembanding1);

  return 0;
}

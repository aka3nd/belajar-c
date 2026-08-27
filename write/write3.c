#include <unistd.h>

int main(){
  const char message[] = "saatnya makan yang enak brow\n";
  write(1,message,sizeof(message) - 1);
  return 0;
}

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    printf("=== Ukuran tipe data ===\n\n");

    printf("int       : %zu byte = %zu bit\n",
           sizeof(int), sizeof(int) * 8);

    printf("int *     : %zu byte = %zu bit\n",
           sizeof(int *), sizeof(int *) * 8);

    printf("long      : %zu byte = %zu bit\n",
           sizeof(long), sizeof(long) * 8);

    printf("long long : %zu byte = %zu bit\n",
           sizeof(long long), sizeof(long long) * 8);

    printf("char      : %zu byte = %zu bit\n",
           sizeof(char), sizeof(char) * 8);

    return 0;
}

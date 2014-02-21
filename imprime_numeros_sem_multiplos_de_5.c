#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1;

    while (x <= 100) {
        if (x%5 != 0) {
            printf("%d \n", x);
        }
        x++;
    }

    return 0;
}

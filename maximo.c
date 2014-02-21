#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, maior = -1;

    while (1) {
        scanf("%d", &numero);

        if (numero < 0) {
            if (maior == -1) {
                maior = numero;
            }
            break;
        }

        if (numero > maior) {
                maior = numero;
        }
    }

    printf("\nO maior numero digitado foi %d.\n", maior);

    return 0;
}

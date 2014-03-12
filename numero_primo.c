#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {

    int numero;
    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if (numero < 2) {
        printf("\nO numero digitado eh menor do que 2.");

    } else if (numero % 2 == 0) {
        printf("\nO numero %d nao eh primo, pois eh um par maior do que 2.\n", numero);

    } else {

        int candidato_divisor = 3;
        while (candidato_divisor <= sqrt(numero)) {
            if (numero % candidato_divisor == 0) {
                printf("\nO numero %d nao eh primo. Eis um fator primo seu: %d.\n", numero, candidato_divisor);
                break;
            }
            candidato_divisor += 2;
        }
    }

    printf("O numero %d eh primo.\n", numero);

    return 0;
}

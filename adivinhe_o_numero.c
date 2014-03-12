#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sortear(int a, int b) {
    return rand() % (b-a+1) + a;
}

int main()
{
    srand(time(NULL));

    int numero = sortear(1, 100);
    int chute = -1;
    int tentativas = 0;

    printf("\nTente adivinhar o numero sorteado (entre 1 e 100): ");

    while (1)  {
    // qualquer coisa diferente de zero eh considerado VERDADEIRO
    // (portanto, este eh um loop potencialmente infinito, que so termina quando executar um break)
        scanf("%d", &chute);
        tentativas++;

        if (chute == numero) {
            printf("\nParabens! Voce acertou em %d tentativa(s).\n", tentativas);
            break;
        }

        if (chute < numero) {
            printf("\nO numero sorteado eh maior do que %d.", chute);
        } else {
            printf("\nO numero sorteado eh menor do que %d.", chute);
        }
        printf("\nTente novamente: ");
    }
    return 0;
}

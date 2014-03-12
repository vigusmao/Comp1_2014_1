#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogar_dado_honesto() {
    return rand() % 6 + 1;
}

int jogar_dado_desonesto() {

    int x = rand() % 1000;
    if (x < 80) {
        return 1;
    } else if (x < 300) {
        return 2;
    } else if (x < 450) {
        return 3;
    } else if (x < 600) {
        return 4;
    } else if (x < 750) {
        return 5;
    } else {
        return 6;
    }
}


int main()
{
    srand(time(NULL));

    int repeticoes;
    printf("\nQuantas repeticoes? ");
    scanf("%d", &repeticoes);

    int pontos_trio = 0, pontos_dois_pares = 0;

    int i = 1;
    while (i <= repeticoes) {
        int dado1 = jogar_dado_honesto();
        int dado2 = jogar_dado_honesto();
        int dado3 = jogar_dado_honesto();
        int dado4 = jogar_dado_honesto();

        if ((dado1 == dado2) && (dado2 == dado3)) {  // um trio
            pontos_trio++;
        }

        if ((dado1 == dado2) && (dado3 == dado4)) {  // dois pares na sequencia
            pontos_dois_pares++;
        }
        i++;
    }
    printf("\nTrios = %d", pontos_trio);
    printf("\nDois pares seguidos = %d", pontos_dois_pares);
}

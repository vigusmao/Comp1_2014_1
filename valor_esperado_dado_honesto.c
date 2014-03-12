#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogar_dado() {
    return rand() % 6 + 1;
}


int main()
{
    srand(time(NULL));
    int resultado, total = 0, i = 1;

    float repeticoes;
    printf("\nQuantas repeticoes? ");
    scanf("%f", &repeticoes);

    while (i <= repeticoes) {
        resultado = jogar_dado();
        total = total + resultado;
        i++;
    }

    printf("%.8f", total / repeticoes);

    return 0;
}

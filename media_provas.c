#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n Digite a nota da P1: ");
    float P1;
    scanf("%f", &P1);

    printf("\n Digite a nota da P2: ");
    float P2;
    scanf("%f", &P2);

    float M;
    M = (P1 + P2) / 2;

    if (M >= 6) {
        printf("\n Aprovado com media %.2f, parabens!!!", M);
        return 0;
    }

    if (M < 3) {
        printf("\n Reprovado com media %.2f", M);
        return 0;
    }

    float F;
    F = 10 - M;

    printf("\n Voce ficou com media %.2f e precisa tirar %.2f na PF", M, F);

    return 0;
}

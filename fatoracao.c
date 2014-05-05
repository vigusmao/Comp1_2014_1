#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef struct {
    int base;
    int expoente;
} FATOR;

void fatorar1(int n) {
    printf("\n%d = ", n);
    FATOR* fatores = (FATOR*) malloc((log2(n) + 1) * sizeof(int));

    int quant_fatores = 0;
    fatores[0].base = 2;
    fatores[0].expoente = 0;

    int divisor = 2;
    while (n > 1) {
        if (n % divisor == 0) {
            if (divisor != fatores[quant_fatores].base) {
                if (fatores[quant_fatores].expoente > 0) {
                    quant_fatores++; // acabou de fechar um fator
                }
                fatores[quant_fatores].base = divisor;
                fatores[quant_fatores].expoente = 0;
            }
            fatores[quant_fatores].expoente++;
            n /= divisor;
        } else {
            divisor++;
        }
    }
    fatores[++quant_fatores].base = 0;

    int i = 0;
    while (fatores[i].base != 0) {
        printf("%d", fatores[i].base);
        if (fatores[i].expoente > 1) {
            printf("**%d", fatores[i].expoente);
        }
        if ((fatores[i].expoente > 0) && (fatores[i+1].base != 0)) {
            printf(" . ");
        }
        i++;
    }
}

int main() {

    int numero;
    printf("\nDigite um inteiro positivo: ");
    scanf("%d", &numero);

    fatorar1(numero);

    printf("\n\n");

    return 0;
}

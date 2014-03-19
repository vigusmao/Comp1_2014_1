#include<stdlib.h>
#include<stdio.h>

int f(int n) {
    return (n % 2) ? 3*n+1 : n/2;
}

int sequencia(int x, int imprimir) {
    int cont = 1;
    while (x != 1) {
        if (imprimir) {
            printf("%d ", x);
        }
        x = f(x);
        cont++;
    }
    if (imprimir) {
        printf("1");
    }
    return cont;
}

int main() {
    int inicio, fim;
    printf("\nDigite o inicio e o fim do intervalo separados por um espaco: ");
    scanf("%d %d", &inicio, &fim);

    int i, maior_seq = 0, valor_da_maior_seq;
    for (i = inicio; i <= fim; i++) {
        int resultado = sequencia(i, 0);
        if (resultado > maior_seq) {
            maior_seq = resultado;
            valor_da_maior_seq = i;
        }
    }
    printf("\nA maior sequencia eh a de %d, com tamanho %d", valor_da_maior_seq, maior_seq);
    printf("\nSequencia: ");
    sequencia(valor_da_maior_seq, 1);

    printf("\n\n");
}

#include<stdio.h>

int imprime_piramide(int n_linhas) {
    int i, tamanho, cont=0;
    for (i=1; i<=n_linhas; i++) {
        tamanho = i;
        imprime_linha(tamanho);
        cont = cont + tamanho;
    }
    for (i=n_linhas-1; i>=1; i--) {
        tamanho = i;
        imprime_linha(tamanho);
        cont += tamanho;
    }
    return cont;
}

void imprime_linha(int tamanho) {
    printf("\n");
    int i;
    for (i=1; i<=tamanho; i++) {
        printf("*");
    }
}

int main() {
    int tamanho, total_asteriscos;
    printf("Tamanho da piramide: ");
    scanf("%d", &tamanho);
    total_asteriscos = imprime_piramide(tamanho);
    printf("\nTotal de asteriscos = %d", total_asteriscos);
    printf("\n\n");
    return 0;
}

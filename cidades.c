#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char nome[30];
    char UF[3];
    int populacao;
    float PIB;
} CIDADE;

void flush() {
    // flush do buffer do teclado
    while (fgetc(stdin) == EOF);
}

void remove_linebreak(char* string) {
    if (string[strlen(string)-1] == '\n') {
        string[strlen(string)-1] = 0;
    }
}

void imprime_cidade(CIDADE* c) {
    printf("\nNome: %s", c->nome);
    printf("\nUF: %s", c->UF);
    printf("\nPopulacao: %d", c->populacao);
    printf("\nPIB: %f", c->PIB);
}

void listar_por_UF(CIDADE* cidades, int quant_cidades, char UF[3]) {
    int i;
    for(i=0; i<quant_cidades; i++) {
        if (strcmp(cidades[i].UF, UF) == 0) {
            imprime_cidade(&cidades[i]);
        }
    }
}

CIDADE* encontrar_mais_populosa(CIDADE* cidades, int quant_cidades) {
    int i;
    CIDADE* metropole = &cidades[0];
    for(i=1; i<quant_cidades; i++) {
        if (cidades[i].populacao > metropole->populacao) {
            metropole = &cidades[i];
        }
    }
    return metropole;
}

int main() {
    int i, n;
    printf("\nQuantas cidades? ");
    scanf("%d", &n);

    // aloca memoria para um array de n cidades
    CIDADE* cidades = (CIDADE*) malloc(n*sizeof(CIDADE));

    for (i=0; i<n; i++) {
        flush();

        printf("\nDigite o nome da cidade %d: ", i+1);
        fgets(cidades[i].nome, 30, stdin);
        remove_linebreak(cidades[i].nome);

        printf("\nDigite a UF: ");
        fgets(cidades[i].UF, 3, stdin);
        remove_linebreak(cidades[i].UF);

        printf("\nDigite a populacao: ");
        scanf("%d", &cidades[i].populacao);

        printf("\nDigite o PIB: ");
        scanf("%f", &cidades[i].PIB);
    }

    //listar_por_UF(cidades, n, "RJ");
    imprime_cidade(encontrar_mais_populosa(cidades, n));

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char nome[50];
    int DRE;
    float media;
} ALUNO;

void imprime_aluno(ALUNO aluno) {
    printf("\n\nNome ---> %s", aluno.nome);
    printf("\nDRE ---> %d", aluno.DRE);
    printf("\nmedia ---> %f", aluno.media);
}

void aumenta_media(ALUNO* ptr_aluno, float pontos) {
    ptr_aluno->media += pontos;
}

int main() {
    ALUNO x;
    strcpy(x.nome, "Fulano");
    x.DRE = 1234;
    x.media = 8.5;

    imprime_aluno(x);
    aumenta_media(&x, 0.5);
    imprime_aluno(x);

    printf("\n\n");
    return 0;
}

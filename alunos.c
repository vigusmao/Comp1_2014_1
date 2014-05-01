#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char nome[50];
    char email[30];
    float nota;
} ALUNO;

void imprime_aluno(ALUNO aluno) {
    printf("\nNome: %s", aluno.nome);
    printf("\nE-mail: %s", aluno.email);
    printf("\nNota: %1f", aluno.nota);
}

void processa_notas(ALUNO alunos[], int quant_alunos) {
    if (quant_alunos == 0) {
        return; // nao ha nada a ser processado
    }

    int i;
    float somatorio = alunos[0].nota;
    int indice_melhor_aluno = 0, indice_pior_aluno = 0;

    for (i = 1; i < quant_alunos; i++) {
        somatorio += alunos[i].nota;
        if (alunos[i].nota < alunos[indice_pior_aluno].nota) {
            indice_pior_aluno = i;
        }
        if (alunos[i].nota > alunos[indice_melhor_aluno].nota) {
            indice_melhor_aluno = i;
        }
    }
    printf("\nMedia ---> %f", somatorio / quant_alunos);
    printf("\n\nMelhor aluno:");
    imprime_aluno(alunos[indice_melhor_aluno]);
    printf("\n\nPior aluno:");
    imprime_aluno(alunos[indice_pior_aluno]);
}

int main() {
    ALUNO alunos[100];
    int i;
    for (i = 0; i < 100; i++) {
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strlen(alunos[i].nome)-1] = '\0'; // troca o '\n' final por '\0'
        if (strcmp(alunos[i].nome, "") == 0) {
            break;
        }

        fgets(alunos[i].email, 30, stdin);
        alunos[i].email[strlen(alunos[i].email)-1] = '\0'; // troca o '\n' final por '\0'

        scanf("%f", &alunos[i].nota);

        // flush do teclado
        while(fgetc(stdin) == EOF);
    }

    processa_notas(alunos, i);

    printf("\n\n");
    return 0;
}

#include <stdio.h>
#include <strings.h>

struct contato {
    char nome[50];
    int telefone;
};

void inserir(struct contato array_de_contatos[], int* ptr_quantidade) {
    char novo_nome[50];
    int novo_telefone;

    printf("Qual o nome? ");
    fgets(novo_nome, 50, stdin);
    if (strcmp(novo_nome, "") == 0) { // se deixar o nome em branco,
        return;                       // sai da funcao sem inserir nada
    }
    strcpy(array_de_contatos[*ptr_quantidade].nome, novo_nome);

    printf("Qual o telefone? ");
    scanf("%d", &novo_telefone);

    array_de_contatos[*ptr_quantidade].telefone = novo_telefone;

    (*ptr_quantidade)++; // incremento o inteiro apontado pelo ponteiro ptr_quantidade
    printf("Insersao realizada com sucesso. Total de contatos = %d.\n", *ptr_quantidade);
}

void consultar(struct contato array_de_contatos[], int quantidade) {
    char nome_consulta[50];
    int i;

    printf("Deseja consultar o telefone de quem? ");
    fgets(nome_consulta, 50, stdin);
    for (i = 0; i < quantidade; i++) {
        if (strcmp(array_de_contatos[i].nome, nome_consulta) == 0) { // encontrou!!
            printf("O telefone eh %d.\n", array_de_contatos[i].telefone);
            break;
        }
    }
    if (i == quantidade) { // nesse caso, nunca deu break no for acima, portanto nao encontrou o telefone!
        printf("Este telefone nao consta na agenda.");
    }
}

int main() {
    struct contato agenda[1000];   // array estatico para 1000 contatos
    int quant_contatos = 0;

    int continuar = 1;
    while (continuar && (quant_contatos < 1000)) {
        printf("\nQual a opcao --- (I)nserir, (C)onsultar, ou (F)inalizar? ");
        char opcao;
        scanf(" %c", &opcao);     // note o espaco antes do %c
        while (getchar() == EOF);    // se livra do caracter correspondente a fim de linha

        switch (opcao) {
        case 'I':
        case 'i':
            inserir(agenda, &quant_contatos);   // detalhe: aqui passamos o ENDERECO da variavel quant_contatos,
            break;                              // pois queremos que ela possa ser modificada dentro da funcao inserir()
        case 'C':
        case 'c':
            consultar(agenda, quant_contatos);
            break;
        case 'F':
        case 'f':
            printf("Tchau!");
            continuar = 0;
            break;
        default:
            printf("Opcao invalida!");
        }
    }

    printf("\n\n");
    return 0;
}

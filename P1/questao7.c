#include<stdio.h>
#include<stdlib.h>

int eh_senha_valida(int senha) {
    return ((senha >= 100000) && (senha <= 999999));
}

int main() {

    int senha, confirmacao;

    while(1) {
        printf("\nDigite a senha: ");  // 1
        scanf("%d", &senha);           // 2
        if (!eh_senha_valida(senha)) {  // 3
            printf("Senha deve estar 100000 e 999999."); //4
            continue; // volta ao comeco do while
        }
        printf("Repita a senha: "); // 6
        scanf("%d", &confirmacao);
        if (confirmacao != senha) {   // 7
            printf("Senhas diferentes!");
            continue; // volta ao comeco do while
        }
        printf("Senha cadastrada com sucesso."); // 8
        break; // para sair do while infinito
    }

    printf("\n\n");
    return 0;
}

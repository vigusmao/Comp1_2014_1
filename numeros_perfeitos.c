#include<stdlib.h>
#include<stdio.h>


// retona 1 se o numero passado como parametro eh um numero perfeito
// retorna 0 caso contrario
int eh_perfeito(int numero) {
    if (numero < 1) {
        return 0;
    }
    int d = 1, soma = 0;
    while (d < numero) {
        if (numero % d == 0) {
            soma += d;
        }
        d++;
    }

    if (soma == numero) {
        return 1;
    } else {
        return 0;
    }

    // todo esse bloco if...else pode ser substituido por uma unica linha:
    //    return soma == numero;
    // (ou seja, pode-se retornar diretamente o resultado da comparacao:
    //  se for igual, a comparacao resulta em 1; caso contrario, resulta em 0)
}


int main() {
    int x = 1;
    while (x <= 10000) {
        if (eh_perfeito(x)) {
            printf("\n%d", x);
        }
        x++;
    }

    printf("\n\n");
    return 0;
}

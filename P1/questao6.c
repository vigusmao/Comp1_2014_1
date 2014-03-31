#include<stdio.h>
#include<stdlib.h>

int eh_divisor(int numero, int candidato_divisor) {
    if (numero % candidato_divisor == 0) {
        return 1;
    }
    return 0;
}

int menor(int a, int b) {
    return (a <= b) ? a : b;
}


int main() {
    int x, y, i;
    printf("\nDigite o primeiro inteiro: ");
    scanf("%d", &x);
    printf("\nDigite o segundo inteiro: ");
    scanf("%d", &y);

    i = menor(x, y);
    while (i > 1) {
        if (eh_divisor(x, i) && eh_divisor(y, i)) {
            break;
        }
        i--;
    }

    printf("\nMDC de %d e %d = %d", x, y, i);
    return 0;
}

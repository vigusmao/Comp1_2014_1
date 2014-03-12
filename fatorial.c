#include<stdio.h>

int fatorial(int numero) {

    int resultado = 1;
    int x = 1;

    while (x <= numero) {
        resultado = resultado * x;
        x++;
    }

    return resultado;
}


int combinacao(int n, int p) {
    return fatorial(n)/(fatorial(n-p)*fatorial(p));
}


int main() {

    int n = 0, p = 0;

    while (n <= 15) {
        printf("\n%d! = %d", n, fatorial(n));
        n++;
    }

    n = 0;
    while (n <= 6) {
        p = 0;
        while (p <= n) {
            printf("\nCombinacao(%d,%d) = %d", n, p, combinacao(n,p));
            p++;
        }
        n++;
    }

    printf("\n\n");

    return 0;
}

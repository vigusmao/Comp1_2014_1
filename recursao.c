#include <stdlib.h>
#include <stdio.h>

int debug = 0; // variavel global

// Fibonacci nao-recursivo
long fib_naorecursivo(long n) {
    if (debug) {
        printf("\nEntrei na funcao nao recursiva!");
    }
    long a = 1, b = 1, i = 1;
    while (i < n) {
        int aux = b;
        b = a+b;
        a = aux;
        i++;
    }
    return b;
}

// Fibonacci recursivo
int fib(int n) {
    if (n <= 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    if (debug) {
        printf("\nEstou em modo debug!");
    }

    int numero;
    scanf("%d", &numero);
    printf("fibonacci(%d) = %lu", numero, fib_naorecursivo(numero));

    printf("\n\n");
    return 0;
}

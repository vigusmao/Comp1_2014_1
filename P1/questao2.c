#include <stdio.h>


int sequencia(int n) {
    int i, total = 0;
    for (i=1; i<=n; i+=2) {
        total += i;
        if (i==5) {
            continue;
        }
        total *= 2;
    }
    return total;
}


int main() {
    printf("Resultado = %d\n\n", sequencia(8)); // vai imprimir 44
}

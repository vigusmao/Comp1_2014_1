#include<stdlib.h>
#include<stdio.h>

int sinal_termo(int termo) {
    return (termo % 2) ? -1 : 1;
}

double pi_serie1(int t) {
    double resultado = 4;
    int i;
    for (i = 1; i < t; i++) {
        resultado += 4.0/(2*i+1) * sinal_termo(i);
    }
    return resultado;
}

double pi_serie2(int t) {
    double resultado = 3;
    int i;
    for (i = 1; i < t; i++) {
        resultado += 4.0/ ((2*i)*(2*i+1)*(2*i+2)) * sinal_termo(i+1);
    }
    return resultado;
}

// outra maneira de se implementar pela serie 2
//double pi_serie2(int t) {
//    double resultado = 3;
//    int i, p = 2, s = 3, r = 4, sinal = 1;
//    for (i = 1; i <= t-1; i++) {
//
//        resultado += 4.0 / (p*s*r*sinal);
//        p += 2;
//        s += 2;
//        r += 2;
//        sinal *= -1;
//    }
//    return resultado;
//}


int main() {
    int max_termos;
    printf("Qual o numero maximo de termos? ");
    scanf("%d", &max_termos);

    int i;
    for (i = 1; i <= max_termos; i++) {
        printf("\n\nNumero de termos = %d", i);
        printf("\npi (pela serie 1) = %.32f", pi_serie1(i));
        printf("\npi (pela serie 2) = %.32f", pi_serie2(i));
    }

    printf("\n\n");
    return 0;
}

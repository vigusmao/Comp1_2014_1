#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* encontrar_divisores(int x) {
    //int divisores[1000];  // alocacao estatica
    int* divisores;
    divisores = (int*) malloc(2*sqrt(x)*sizeof(int));

    int d = 1, quant_divisores = 0;
    while (d <= x) {
        if (x % d == 0) {
            divisores[quant_divisores++] = d;
        }
        d++;
    }
    return divisores;
}

void encontrar_divisores_2(int x, int* divisores) {
    int d = 1, quant_divisores = 0;
    while (d <= x) {
        if (x % d == 0) {
            divisores[quant_divisores++] = d;
        }
        d++;
    }
}

int encontrar_maior(int* elementos, int quant_elementos) {
    int maior = elementos[0];
    int i;
    for (i = 1; i < quant_elementos; i++) {
        if (elementos[i] > maior) {
            maior = elementos[i];
        }
    }
    return maior;
}

int main() {
   int numero;
   printf("\nDigite um numero inteiro: ");
   scanf("%d", &numero);

   int* divisores;
   //divisores = encontrar_divisores(numero);
   divisores = (int*) malloc(2*sqrt(numero)*sizeof(int));
   encontrar_divisores_2(numero, divisores);

   int* tmp;
   tmp = divisores;
   do {
       printf("%d ", *tmp);
   } while(*tmp++ != numero);

   free(divisores);


   int array_de_inteiros[5] = {12, 4, 6, 22, -4};
   int* y;
   y = (int*) malloc(sizeof(int));
   *y = encontrar_maior(array_de_inteiros, 5);
   print("\nMaior = %d", *y)

   printf("\n\n");
   return 0;
}

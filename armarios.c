#include <stdio.h>
#include <stdlib.h>

#define N_ARMARIOS 1000

int main() {
    int armarios[N_ARMARIOS+1];
    int i, aluno, indice_arm;

   for (i=1; i<=N_ARMARIOS; i++) {
        armarios[i] = 0; // armario fechado
    }

    for (aluno=1; aluno<=N_ARMARIOS; aluno++) {
        for (indice_arm=1; indice_arm<=N_ARMARIOS; indice_arm++) {
            if (indice_arm % aluno == 0) {
                armarios[indice_arm] = 1 - armarios[indice_arm];
            }
        }
    }

    printf("\n");
    for (i=1; i<=N_ARMARIOS; i++) {
        if (armarios[i]==1) {
            printf("%d ", i);
        }
    }

    printf("\n\n");
    return 0;
}

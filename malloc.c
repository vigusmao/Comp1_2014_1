#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nome[50];
    int DRE;
    float media;
} ALUNO;


int main() {
    int x = 7;
    int* y;
    int n;
    printf("\nQuantos elementos? ");
    scanf("%d", &n);
    y = (int*) malloc(n*sizeof(int));
    printf("\nx ---> %d", x);
    printf("\n*y ---> %d", *y);
    y[0] = 8;
    y[1] = 18;
    y[2] = 28;
    int i;
    for (i = 0; i < n; i++) {
        printf("\ny[%d] ---> %d", i, y[i]);
    }
    printf("\nx ---> %d", x);
    printf("\n*y ---> %d", *y);
    free(y);
    printf("\n\n");
    return 0;
}

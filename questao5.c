#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sortear() {
    return rand() % 3 + 1;
}

void traduzir(int n) {
    if (n == 1) {
        printf("pedra");
    } else if (n == 2) {
        printf("papel");
    } else if (n == 3) {
        printf("tesoura");
    }
}

int main() {
    srand(time(NULL));
    int a, b;
    a = sortear();
    b = sortear();
    printf("\nJogador A --> ");
    traduzir(a);
    printf("\nJogador B --> ");
    traduzir(b);
    if (a == b) {
        printf("\nEmpate.");
    } else if (( (a==3) && (b==2) ) ||
               ( (a==2) && (b==1) ) ||
               ( (a==1) && (b==3) ) ) {
        printf("\nO Jogador A venceu.");
    } else {
        printf("\nO Jogador B venceu.");
    }
    printf("\n\n");
    return 0;
}


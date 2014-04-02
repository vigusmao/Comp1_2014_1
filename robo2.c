#include <stdio.h>
#include <time.h>
#include <math.h>

#define N_TESTES 1000

void desenhar(int pos_robo, int pos_obj) {
    int i;
    for (i = 1; i <= 80; i++) {
        if ((i == pos_robo) && (i == pos_obj)) {
            printf("*");
        } else if (i == pos_robo) {
            printf("R");
        } else if (i == pos_obj) {
            printf("O");
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int sortear(int a, int b) {
    return rand() % (b-a+1) + a;
}

int mover(int pos_inicial_robo, int pos_final_robo, int pos_obj) {
    int pos_robo = pos_inicial_robo;
    while (pos_robo != pos_final_robo) {
        //aguardar(1);
        desenhar(pos_robo, pos_obj);
        if (pos_robo == pos_obj) {
            return 1;
        }
        pos_robo += (pos_final_robo > pos_inicial_robo) ? 1 : -1;
    }
    return 0;
}

void aguardar(int n_segundos) {
    int inicio = time(NULL);
    while (1) {
        int y = time(NULL);
        if (y - inicio >= n_segundos) {
            break;
        }
    }
}

int calcular_destino_PA(int origem, int movimento) {
    return origem + movimento * (movimento % 2 ? 1 : -1);
}

int calcular_destino_PG(int origem, int movimento) {
    return origem + pow(2, movimento-1) * (movimento % 2 ? 1 : -1);
}

int simulacao() {
    int pos_objeto = sortear(20, 60);
    int pos_inicial_robo = 40;
    int total_passos = 0;
    int i = 1;
    int origem = pos_inicial_robo, destino;

    while (1) {
        destino = calcular_destino_PG(origem, i);
        int resultado = mover(origem, destino, pos_objeto);

        if (resultado) {  // encontrou o objeto!!
            total_passos += resultado;
            break;
        }

        // nao encontrou o objeto ainda...
        i++;
        total_passos += abs(destino - origem);
        origem = destino;
    }
    return total_passos;
}

int main() {

    srand(time(NULL));
    int total_global = 0;

    int teste;
    for (teste = 1; teste <= N_TESTES; teste++) {
        total_global += simulacao();
    }

    printf("\n\nNumero medio de passos = %.2f\n\n", ((float)total_global)/N_TESTES);
    return 0;
}


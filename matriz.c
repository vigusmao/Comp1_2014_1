#include<stdio.h>
#include<stdlib.h>

int main() {

   int** notas;    // 5x7
   notas = (int**) malloc(5 * sizeof(int*));

   int i;
   for (i=0; i<5; i++) {
      notas[i] = (int*) malloc(7 * sizeof(int));
   }

   notas[0][0] = 10;
   notas[0][1] = 8;
   // etc...

   for (i=0; i<5; i++) {
       free(notas[i]);
   }
   free(notas);

   return 0;
}

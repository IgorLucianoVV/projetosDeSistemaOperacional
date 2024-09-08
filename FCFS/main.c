#include <stdio.h>
#define max 30

int main(){
   int i, tempoChegada[max], tempoExecucao[max], n, wt = 0, tat = 0;
   float media_tat, media_wt;
   //const tempoChegada[1] = 0;//Eu deixo ou não, pq por ser o 1 na chegada ele não tem que esperar ninguem.

   printf("Quantidade de processos: ");
   scanf("%d", &n);

   printf("Tempo de chegada de cada processo: ");
   for(i = 0; i < n; i++){
        scanf("%d", &tempoChegada[i]);
    }

    printf("Tempo de execução de cada processo: ");
    for(i = 0; i < n; i++){
        scanf("%d", &tempoExecucao[i]);
    }

    printf("\n---------------------------------------------\n");
    printf("| Processo | Tempo de Chegada | Tempo de Execução |\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < n; i++){
        printf("|    P%d    |         %2d        |          %2d         |\n", i+1, tempoChegada[i], tempoExecucao[i]);
    }
    printf("---------------------------------------------\n");


    for(i = 0; i < n; i++){
        wt += tempoChegada[i];
        tat += tat + tempoExecucao[i] - tempoChegada[i];
    }


    media_tat = tat / n;
    media_wt = wt / n;

    printf("\n Tempo médio de fila: %2.f\n", media_wt);
    printf(" Tempo médio de turn around: %2.f", media_tat);

    //Precisa fazer a parte em que ele pegar um processo e deixa em pronto e o resto em bloqueado?
   
}
#include <stdio.h>
#include <conio.h>
#define max 30



int main(){
    
    int n, i, j, aux, p[max], bt[max], wt[max], tat[max];
    float media_wt, media_tat;

    printf("Quantidade de procesos: ");
    scanf("%d", &n);

    printf("Tempo de cada processo: ");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    } 

    printf("Tempo de Burst de cada processo: ");
    for(i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j <n-i-1; j++){
            if(bt[j] > bt[j+1]){
                aux = p[j];
                p[j] = p[j+1];
                p[j+1] = aux;

                aux = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = aux;
            }
        }
    }

    printf("Processo\t burst time\t waiting time\t turn around time\n");
    for (i = 0; i < n; i++){
        wt[i] = 0;
        tat[i] = 0;
        for(j = 0; j < i; j++){
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];

        media_wt += wt[i];
        media_tat += bt[i];
        printf("%d\t          %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    media_wt /= n;
    media_tat /= n;
    printf("Tempo médio de espera pra um processo ficar na fila = %f\n" ,media_wt);
    printf("Tempo médio do turn around time = %f", media_tat);

    return 0;

}
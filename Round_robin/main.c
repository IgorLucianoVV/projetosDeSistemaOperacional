/*Garbriel Maia
Carlos Eduardo*/

#include<stdio.h>

int main() {
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;

    printf("Número de processos: ");
    scanf("%d", &n);
    printf("Tempo de burst de cada processo: ");

    for(i = 0; i < n; i++){
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Digite o tempo de quantum: ");
    scanf("%d", &qt);

    while (1) {
        for(i = 0, count = 0; i < n; i++) {
            temp = qt;
            if(rem_bt[i] <= 0) {
                count++;
                continue;
            }
            if(rem_bt[i] > qt) {
                rem_bt[i] = rem_bt[i] - qt;
            } else {
                if(rem_bt[i] >= 0) {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
                sq = sq + temp;
                tat[i] = sq;
            }
        }

        if(n == count) {
            break;
        }
    }

    printf("\nProcesso\tTempo de burst\tTempo de turnaround\tTempo de espera\n");
    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], tat[i], wt[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("Tempo médio de espera = %f\n", awt);
    printf("Tempo médio de turnaround = %f", atat);

    return 0;
}

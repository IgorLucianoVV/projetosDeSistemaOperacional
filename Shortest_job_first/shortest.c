#include <stdio.h>
#include <conio.h>
#define max 30

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int i,j,n,p[max],bt[max],wt[max],tat[max];
    float media_wt = 0, media_tat = 0;

    printf("Diga a quantidade de processos: ");
    scanf("%d", &n);
    printf("Diga o tempo de cada processo: ");
    for(i = 0;i<n;i++){
        scanf("%d", &p[i]);
    } 

    printf("Diga o tempo de burst do processo: ");
    for(i = 0; i<n; i++){
        scanf("%d", &bt[i]);
    }

    for(i = 0; i<n; i++){
        for(j = 0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                swap(&bt[j], &bt[j+1]);

                // aux = bt[j] 
                // bt[j] = bt[j+1]
                // bt[j+1] = aux
                swap(&p[j], &p[j+1]);
            }
        }
    }


    
    printf("Processo\t burst time\t waiting time\t turn around time\n");
    for(i=0; i<n; i++){
        wt[i] = 0;
        tat[i] = 0;
        for(j = 0; j< i; j++){
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        media_wt = media_wt+wt[i];
        media_tat = media_tat+tat[i];
        printf("%d\t          %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    media_wt = media_wt/n;
    media_tat = media_tat/n;
    printf("Avarage waiting time = %f\n" ,media_wt);
    printf("Avarage turn around time = %f", media_tat);

    return 0;
}





#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES 3 
#define EMPTY_FRAME -1 

typedef struct {
    int pageNumber;
    int referenceBit;
    int contador;
} PageFrame;

void replacePage(PageFrame *memory, int numFrames, int pageReferenced, int *pointer) {
    while (1) {
        if (memory[*pointer].referenceBit == 0) {
            // Substitui a página
            printf("Substituiu página %d (Contador: %d)\n", memory[*pointer].pageNumber, memory[*pointer].contador);
            memory[*pointer].pageNumber = pageReferenced;
            memory[*pointer].referenceBit = 1;
            memory[*pointer].contador = 0; 
            break;
        } else {
            memory[*pointer].referenceBit = 0;
            memory[*pointer].contador = 0; 
        }
        *pointer = (*pointer + 1) % numFrames; 
    }
}

int main() {
    PageFrame memory[NUM_FRAMES];
    int pageReferences[] = {0, 1, 1, 2, 3, 0, 4, 1, 2, 5, 3, 4, 6}; 
    int numReferences = sizeof(pageReferences) / sizeof(pageReferences[0]);
    int pointer = 0; 
    int i, j;

    for (i = 0; i < NUM_FRAMES; i++) {
        memory[i].pageNumber = EMPTY_FRAME; 
        memory[i].referenceBit = 0;
        memory[i].contador = 0;
    }

    for (i = 0; i < numReferences; i++) {
        int pageReferenced = pageReferences[i];
        int pageFound = 0;

        for (j = 0; j < NUM_FRAMES; j++) {
            if (memory[j].pageNumber == pageReferenced) {
                memory[j].referenceBit = 1; 
                memory[j].contador++; 
                pageFound = 1;
                printf("Página %d já está referenciada na memória (Contador: %d)\n", pageReferenced, memory[j].contador);
                break;
            }
        }

        if (!pageFound) {
            replacePage(memory, NUM_FRAMES, pageReferenced, &pointer);
        }

        for (j = 0; j < NUM_FRAMES; j++) {
            memory[j].contador >>= 1; 
        }

        printf("Estado da memória após referência %d: ", pageReferenced);
        for (j = 0; j < NUM_FRAMES; j++) {
            if (memory[j].pageNumber == EMPTY_FRAME)
                printf("[ - ] ");
            else
                printf("[ %d (C: %d) ] ", memory[j].pageNumber, memory[j].contador);
        }
        printf("\n");
    }

    return 0;
}

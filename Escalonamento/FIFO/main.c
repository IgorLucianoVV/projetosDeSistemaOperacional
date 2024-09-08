#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um processo
typedef struct Process {
    int pid;            // ID do processo
    int priority;       // Prioridade do processo
    int burstTime;      // Tempo de execução do processo
    char name[256];     // Nome do processo
} Process;

// Definição da estrutura de um nó
typedef struct Node {
    Process data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar um novo nó
Node* newNode(Process process) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = process;
    temp->next = NULL;
    return temp;
}

// Função para criar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para adicionar um processo à fila
void enqueue(Queue* q, Process process) {
    Node* temp = newNode(process);
    
    // Se a fila estiver vazia, o novo nó é tanto a frente quanto a traseira
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    // Adiciona o novo nó no final da fila e atualiza o ponteiro traseiro
    q->rear->next = temp;
    q->rear = temp;
}

// Função para remover um processo da fila
Process dequeue(Queue* q) {
    Process dummyProcess = {0, 0, 0, ""};
    
    // Se a fila estiver vazia, retorna um processo vazio
    if (q->front == NULL) {
        return dummyProcess;
    }
    
    // Armazena o nó frontal e move o ponteiro frontal para o próximo nó
    Node* temp = q->front;
    q->front = q->front->next;
    
    // Se o ponteiro frontal se tornar NULL, então a fila está vazia
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    Process process = temp->data;
    free(temp);
    return process;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Função para liberar a memória alocada pela fila
void freeQueue(Queue* q) {
    Node* current = q->front;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(q);
}

int main() {
    Queue* q = createQueue();
    
    // Criação de alguns processos
    Process p1 = {1, 1, 10, "Processo 1"};
    Process p2 = {2, 2, 20, "Processo 2"};
    Process p3 = {3, 3, 30, "Processo 3"};
    
    // Adicionando processos à fila
    enqueue(q, p1);
    enqueue(q, p2);
    enqueue(q, p3);
    
    // Removendo processos da fila e imprimindo suas informações
    Process p = dequeue(q);
    printf("Processo removido: PID = %d, Prioridade = %d, Tempo de execução = %d, Nome = %s\n", p.pid, p.priority, p.burstTime, p.name);
    
    p = dequeue(q);
    printf("Processo removido: PID = %d, Prioridade = %d, Tempo de execução = %d, Nome = %s\n", p.pid, p.priority, p.burstTime, p.name);
    
    if (isEmpty(q)) {
        printf("A fila está vazia\n");
    }
    
    freeQueue(q);
    
    return 0;
}


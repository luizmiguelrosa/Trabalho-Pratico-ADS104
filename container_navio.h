#ifndef CONTAINER_NAVIO_H
#define CONTAINER_NAVIO_H

// Definição da estrutura para Container
typedef struct Container {
    int idContainer;      // Identificação do container
    int idNavio;          // Identificação do navio
    struct Container* next; // Apontador para o próximo container
} Container;

// Definição da estrutura para Navio
typedef struct Navio {
    int idNavio;          // Identificação do navio
    Container* topContainer; // Ponteiro para o topo da pilha de containers
} Navio;

// Declaração das funções
Container* criarContainer(int idContainer, int idNavio);
void empilharContainer(Navio* navio, int idContainer);
Container* desempilharContainer(Navio* navio);
Navio* criarNavio(int idNavio);
void exibirContainers(Navio* navio);
void limparNavio(Navio* navio);

#endif // CONTAINER_NAVIO_H
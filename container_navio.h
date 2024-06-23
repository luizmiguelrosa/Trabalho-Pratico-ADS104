#ifndef CONTAINER_NAVIO_H
#define CONTAINER_NAVIO_H

// Definição da estrutura para Container
typedef struct {
    int idContainer;      // Identificação do container
    int idNavio;          // Identificação do navio
} Container;

// Definição da estrutura para Navio
typedef struct {
    int idNavio;          // Identificação do navio
    int quantidadeMaxConteiner;
    int quantidadeConteiner;
    Container* containers;
} Navio;

// Declaração das funções
Container* criarContainer(int idContainer, int idNavio);
int empilharContainer(Navio* navio, int idContainer);
Container desempilharContainer(Navio* navio);
Navio* criarNavio(int idNavio);
void exibirContainers(Navio* navio);
void limparNavio(Navio* navio);

#endif // CONTAINER_NAVIO_H
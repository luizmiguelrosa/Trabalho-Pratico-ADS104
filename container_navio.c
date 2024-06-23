#include <stdio.h>
#include <stdlib.h>
#include "container_navio.h"

// Função para criar um novo container
Container* criarContainer(int idContainer, int idNavio) {
    Container* novoContainer = (Container*)malloc(sizeof(Container));
    if (novoContainer == NULL) {
        printf("Erro ao alocar memória para o container\n");
        return NULL;
    }
    novoContainer->idContainer = idContainer;
    novoContainer->idNavio = idNavio;
    return novoContainer;
}

// Função para empilhar um container em um navio
int empilharContainer(Navio* navio, int idContainer) {
    if (navio->quantidadeConteiner >= navio->quantidadeMaxConteiner)
        return 0;
    Container* novoContainer = criarContainer(idContainer, navio->idNavio);
    navio->containers[navio->quantidadeConteiner] = *novoContainer;
    navio->quantidadeConteiner++;
    return 1;
}

// Função para desempilhar um container de um navio
Container desempilharContainer(Navio* navio) {
    if (navio->quantidadeConteiner == 0) {
        printf("A pilha de containers esta vazia!\n");
        Container containerVazio = {0, 0};
        return containerVazio;
    }
    navio->quantidadeConteiner--;
    return navio->containers[navio->quantidadeConteiner];
}

// Função para criar um novo navio
Navio* criarNavio(int idNavio) {
    Navio* novoNavio = (Navio*)malloc(sizeof(Navio));
    if (novoNavio == NULL) {
        printf("Erro ao alocar memória para o navio\n");
        return NULL;
    }
    novoNavio->idNavio = idNavio;
    novoNavio->quantidadeMaxConteiner = 50;
    novoNavio->containers = (Container*)malloc(sizeof(Container) * novoNavio->quantidadeMaxConteiner);
    novoNavio->quantidadeConteiner = 0;
    return novoNavio;
}
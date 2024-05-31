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
    novoContainer->next = NULL;
    return novoContainer;
}

// Função para empilhar um container em um navio
void empilharContainer(Navio* navio, int idContainer) {
    Container* novoContainer = criarContainer(idContainer, navio->idNavio);
    if (novoContainer == NULL) {
        return;
    }
    novoContainer->next = navio->topContainer; // Aponta para o atual topo da pilha
    navio->topContainer = novoContainer; // Atualiza o topo da pilha para o novo container
}

// Função para desempilhar um container de um navio
Container* desempilharContainer(Navio* navio) {
    if (navio->topContainer == NULL) {
        printf("A pilha de containers está vazia!\n");
        return NULL;
    }
    Container* containerRemovido = navio->topContainer; // O container a ser removido
    navio->topContainer = navio->topContainer->next; // Atualiza o topo para o próximo container
    return containerRemovido; // Retorna o container removido
}

// Função para criar um novo navio
Navio* criarNavio(int idNavio) {
    Navio* novoNavio = (Navio*)malloc(sizeof(Navio));
    if (novoNavio == NULL) {
        printf("Erro ao alocar memória para o navio\n");
        return NULL;
    }
    novoNavio->idNavio = idNavio;
    novoNavio->topContainer = NULL;
    return novoNavio;
}

// Função para exibir os containers em um navio
void exibirContainers(Navio* navio) {
    Container* atual = navio->topContainer;
    while (atual != NULL) {
        printf("Container ID: %d, Navio ID: %d\n", atual->idContainer, atual->idNavio);
        atual = atual->next;
    }
}

// Função para limpar a memória de todos os containers de um navio
void limparNavio(Navio* navio) {
    Container* containerRemovido;
    while ((containerRemovido = desempilharContainer(navio)) != NULL) {
        free(containerRemovido);
    }
    free(navio);
}

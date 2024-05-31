#include <stdio.h>
#include "container_navio.h"

int main() {
    // Criar um navio
    Navio* navio = criarNavio(1001);

    // Empilhar alguns containers
    empilharContainer(navio, 2001);
    empilharContainer(navio, 2002);
    empilharContainer(navio, 2003);

    // Exibir containers do navio
    printf("Containers no navio %d:\n", navio->idNavio);
    exibirContainers(navio);

    // Desempilhar um container
    Container* removido = desempilharContainer(navio);
    if (removido != NULL) {
        printf("Container removido: ID %d\n", removido->idContainer);
        free(removido);
    }

    // Exibir containers do navio novamente
    printf("Containers no navio %d após remoção:\n", navio->idNavio);
    exibirContainers(navio);

    // Limpar navio e liberar memória
    limparNavio(navio);

    return 0;
}

#include <stdlib.h>

typedef struct 
{
    void ** itens;
    int tamanho_max;
    int primeiro, ultimo;
} Lista;

void limpar(Lista* lista) {
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}

void inicializaLista(Lista* lista, int tamanho_max) {
    lista->itens = (void**) malloc(sizeof(void*) * tamanho_max);
    lista->tamanho_max = tamanho_max;
    limpar(lista);
}

int vazia(Lista* lista) {
    return (lista->primeiro == lista->ultimo);
}

int inserir(void* item, Lista* lista) {
    if (lista->ultimo >= lista->tamanho_max)
        return 0;
    else {
        lista->itens[lista->ultimo] = item;
        lista->ultimo++;
        return 1;
    }
}

int remover(int posicao, Lista* lista) {
    if (vazia(lista))
        return 0;
    for (int i = 0; i < lista->ultimo; i++)
        lista->itens[i] = lista->itens[i + 1];
    lista->ultimo--;
    return 1;
}
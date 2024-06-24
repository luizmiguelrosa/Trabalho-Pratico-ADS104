#include <time.h>
#include <stdbool.h>

int gerarNumero(int menor, int maior) {
    return rand() % (maior - menor + 1) + menor;
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int procura_navio(int idNavio, Lista* navios) {
    for (int i = 0; i < navios->ultimo; i++) {
        Navio* aux = navios->itens[i];
        if (aux->idNavio == idNavio)
            return i;
    }
    return -1;
}

int procura_conteiner(int idConteiner, Lista* porto) {
    for (int i = 0; i < porto->ultimo; i++) {
        Container* aux = porto->itens[i];
        if (aux->idContainer == idConteiner)
            return i;
    }
    return -1;
}

int remover_container(int idConteiner, Lista* porto) {
    int index = procura_conteiner(idConteiner, porto);
    if (index < 0)
        return -1;
    return remover(index, porto);
}

int remover_navio(int idNavio, Lista* navios) {
    int index = procura_navio(idNavio, navios);
    if (index < 0)
        return -1;
    return remover(index, navios);
}
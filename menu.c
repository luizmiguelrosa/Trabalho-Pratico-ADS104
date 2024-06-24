#include "lista.c"
#include "container_navio.c"

void exibir_gerenciar_navio(Lista* porto) {
    exibir_gerenciar_conteineres(porto);

    printf("\n=========================================\n");
    printf("               OPCOES              \n");
    printf("=========================================\n\n");
    printf("  1. Carregar Container Especifico\n");
    printf("  2. Carregar todos os Containers\n");
    printf("  0. Sair\n\n");
    printf("=========================================\n\n");
    
}

void exibir_tabela_navios(Lista* navios) {
    if (vazia(navios)) {
        printf("  +---------------------------------+\n");
        printf("  |      Sem Navios registrados     |\n");
        printf("  +---------------------------------+\n");
    } else {
        printf("+-----------------------+------------------------+\n");
        printf("|    Navios no Porto    |  Quantidade Conteiner  |\n");
        printf("+-----------------------+------------------------+\n");

        for (int i = 0; i < navios->ultimo; i++) {
            Navio* navioAux = navios->itens[i];
            printf("|          %-12d |           %-12d |\n", navioAux->idNavio, navioAux->quantidadeConteiner);
        }
        printf("+-----------------------+------------------------+\n");   
    }
}

void exibir_gerenciar_navios(Lista* navios) {
    exibir_tabela_navios(navios);

    printf("\n=========================================\n");
    printf("               OPCOES              \n");
    printf("=========================================\n\n");
    printf("  1. Carregar Navio\n");
    printf("  2. Descarregar Navio\n");
    printf("  3. Adicionar Navio\n");
    printf("  4. Remover Navio\n");
    printf("  0. Sair\n\n");
    printf("=========================================\n\n");
    
}


void exibir_tabela_conteineres(Lista* porto) {
    if (vazia(porto)) {
        printf("  +---------------------------------+\n");
        printf("  |   Sem conteineres registrados   |\n");
        printf("  +---------------------------------+\n");
    } else {
        printf("+--------------------------+-----------------------+\n");
        printf("|   Conteineres no Porto   |  Navios Responsaveis  |\n");
        printf("+--------------------------+-----------------------+\n");

        for (int i = 0; i < porto->ultimo; i++) {
            Container* container_aux = porto->itens[i];
            printf("|            %-13d |          %-12d |\n", container_aux->idContainer, container_aux->idNavio);
        }
        printf("+--------------------------+-----------------------+\n");   
    }
}

void exibir_gerenciar_conteineres(Lista* porto) {
    exibir_tabela_conteineres(porto);

    printf("\n=========================================\n");
    printf("               OPCOES              \n");
    printf("=========================================\n\n");
    printf("  1. Adicionar Conteiner\n");
    printf("  2. Remover Conteiner\n");
    printf("  0. Sair\n\n");
    printf("=========================================\n\n");
    
}

void exibir_relatorio(int total_containers, int total_ships_waiting) {
    printf("+-------------------------+-------------------+\n");
    printf("|  Conteineres no Porto   |  Navios em Espera |\n");
    printf("+-------------------------+-------------------+\n");
    printf("|           %-13d |        %-10d |\n", total_containers, total_ships_waiting);
    printf("+-------------------------+-------------------+\n");
}

void exibir_menu() {
    printf("\n=========================================\n");
    printf("               TELA INICIAL              \n");
    printf("=========================================\n\n");
    printf("  1. Gerenciar Conteineres no Porto\n");
    printf("  2. Gerenciar Navios na Fila\n");
    printf("  3. Gerar Relatorio\n");
    printf("  0. Sair\n\n");
    printf("=========================================\n\n");
}
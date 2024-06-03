#include <stdio.h>
#include <stdbool.h>
#include "lista.h"
#include "container_navio.c"

#define MaxConteineresPorto 100

void exibir_menu();

void exibir_gerenciar_conteineres(Lista* porto);

int main()
{
    Lista porto;
    inicializaLista(&porto, MaxConteineresPorto);

    bool loop_principal = true;
    while (loop_principal)
    {
        system("cls");
        exibir_menu();

        int escolha;
        printf("  -> ");
        scanf("%d", &escolha);
        
        switch (escolha)
        {
        case 1: //          Gerenciar Conteineres no Porto
            bool loop_conteiner = true;
            while (loop_conteiner)
            {
                system("cls");
                exibir_gerenciar_conteineres(&porto);
                int escolha_container;

                printf("-> ");
                scanf("%d", &escolha_container);

                switch (escolha_container)
                {
                case 1: //          Adicionar Conteiner
                    system("cls");
                    printf("\n===================================================\n");
                    printf("              Adicionando Conteineres                \n");
                    printf("===================================================\n\n");

                    int idContainer, idNavio;
                    
                    printf("  Digite a Identificacao do Conteinere: ");
                    scanf("%d", &idContainer);

                    printf("\n  Digite a Identificacao do Navio Responsavel: ");
                    scanf("%d", &idNavio);
                    
                    Container* conteiner_aux = criarContainer(idContainer, idNavio);

                    if (inserir(conteiner_aux, &porto))
                        printf("\n  [!] Conteiner Adicionado com Sucesso !\n");
                    else
                        printf("\n  [X] Capacidade Maxima de Conteineres Atingida\n");
                    
                    getchar();
                    getchar();

                    break;
                
                default:
                    loop_conteiner = !loop_conteiner;
                    break;
                }
            }
            
            break;
        
        default:
            loop_principal = !loop_principal;
            break;
        }
    }
    
    
    return 0;
}

void exibir_gerenciar_conteineres(Lista* porto) {
    if (vazia(porto)) {
        printf("  +---------------------------------+\n");
        printf("  |   Sem conteineres registrados   |\n");
        printf("  +---------------------------------+\n");
    } else {
        printf("+-------------------------+---------------------+\n");
        printf("|  Conteineres no Porto   | Navios Responsaveis |\n");
        printf("+-------------------------+---------------------+\n");

        for (int i = 0; i < porto->ultimo; i++) {
            Container* container_aux = porto->itens[i];
            printf("|           %-13d |        %-10d |\n", container_aux->idContainer, container_aux->idNavio);
        }
        printf("+-------------------------+---------------------+\n");
    }

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
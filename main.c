#include <stdio.h>
#include <stdbool.h>
#include "menu.c"

#define MaxConteineresPorto 100

int remover_container(int idConteiner, Lista* porto);

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

                system("cls");
                switch (escolha_container)
                {
                case 1: //          Adicionar Conteiner
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

                    break;
                
                case 2: //          Removendo Conteiner
                    exibir_tabela_conteineres(&porto);

                    printf("\n===================================================\n");
                    printf("              Removendo Conteineres                \n");
                    printf("===================================================\n\n");

                    if (!vazia(&porto)) {
                        int idConteiner;

                        printf("  Digite Identificacao do Conteiner que deseja remover: ");
                        scanf("%d", &idConteiner);

                        if (remover_container(idConteiner, &porto))
                            printf("\n  [!] Conteiner removido com Sucesso !\n");
                        else
                            printf("\n  [X] Conteiner inexistente !\n");

                    } else {
                        printf("\n  [X] Sem conteineres registrados !\n");
                    }
                    break;

                default:
                    loop_conteiner = !loop_conteiner;
                    break;
                }

                getchar();
                getchar();
            }
            
            break;
        
        default:
            loop_principal = !loop_principal;
            break;
        }
    }
    
    return 0;
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
        return 0;
    return remover(index, porto);
}
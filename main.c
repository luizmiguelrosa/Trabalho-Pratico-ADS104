#include <stdio.h>
#include "menu.c"
#include "utils.c"

#define MaxConteineresPorto 100
#define MaxNaviosPorto 10

int main()
{
    Lista porto;
    inicializaLista(&porto, MaxConteineresPorto);

    Lista navios;
    inicializaLista(&navios, MaxNaviosPorto);

    bool loop_principal = true;
    while (loop_principal)
    {
        srand(time(NULL));
        limparTela();
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
                limparTela();
                exibir_gerenciar_conteineres(&porto);
                int escolha_container;

                printf("-> ");
                scanf("%d", &escolha_container);

                limparTela();
                switch (escolha_container)
                {
                case 1: //          Adicionar Conteiner
                    printf("\n===================================================\n");
                    printf("              Adicionando Conteineres              \n");
                    printf("===================================================\n\n");

                    int idContainer, idNavio;
                    
                    printf("  Digite a Identificacao do Conteinere: ");
                    scanf("%d", &idContainer);

                    if (!procura_conteiner(idContainer, &porto)) {
                        printf("\n  [X] Conteiner ja registrado !\n");
                        getchar();
                        getchar();
                        break;
                    }

                    printf("\n  Digite a Identificacao do Navio Responsavel: ");
                    scanf("%d", &idNavio);
                    
                    Container* conteiner_aux = criarContainer(idContainer, idNavio);

                    if (inserir(conteiner_aux, &porto))
                        printf("\n  [+] Conteiner Adicionado com Sucesso !\n");
                    else
                        printf("\n  [X] Capacidade Maxima de Conteineres Atingida\n");
                    getchar();
                    getchar();
                    break;
                
                case 2: //          Removendo Conteiner
                    exibir_tabela_conteineres(&porto);

                    printf("\n===================================================\n");
                    printf("               Removendo Conteineres               \n");
                    printf("===================================================\n\n");

                    if (!vazia(&porto)) {
                        int idConteiner;

                        printf("  Digite Identificacao do Conteiner que deseja remover: ");
                        scanf("%d", &idConteiner);

                        if (remover_container(idConteiner, &porto))
                            printf("\n  [+] Conteiner removido com Sucesso !\n");
                        else
                            printf("\n  [X] Conteiner inexistente !\n");

                    } else
                        printf("\n  [X] Sem conteineres registrados !\n");
                    getchar();
                    getchar();
                    break;

                default:
                    loop_conteiner = !loop_conteiner;
                    break;
                }
            }
            
            break;
        
        case 2: //          Gerenciar Navios na Fila
            bool loop_navio = true;
            while (loop_navio) {
                limparTela();
                exibir_gerenciar_navios(&navios);
                int escolha_navio;

                printf("-> ");
                scanf("%d", &escolha_navio);

                limparTela();
                switch (escolha_navio)
                {
                case 1: //  Carregar Navio 
                    exibir_tabela_navios(&navios);

                    printf("\n===================================================\n");
                    printf("                 Carregando Navio                  \n");
                    printf("===================================================\n\n");

                    if (!vazia(&navios)) {
                        int idNavio;
                        printf("  Digite a identificação do Navio desejado: ");
                        scanf("%d", &idNavio);

                        bool loop_carrega_navio = true;
                        while (loop_carrega_navio)
                        {
                            limparTela();
                            Lista portoAux;
                            inicializaLista(&portoAux, MaxConteineresPorto);
                            for (int i = 0; i < porto.tamanho_max; i++){
                                Container * containerAux = porto.itens[i];
                                if (containerAux->idNavio == idNavio)
                                    inserir(containerAux, &portoAux);
                            }

                            exibir_gerenciar_navio(&portoAux);

                            int escolha; // Parou aqui
                            
                        }
                        
                    } else
                        printf("\n  [X] Sem navios registrados !\n");
                    

                    getchar();
                    getchar();
                    break;
                
                case 2: // Descarregar Navio
                    getchar();
                    getchar();
                    break;

                case 3: // Adicionar Navio
                    printf("\n===================================================\n");
                    printf("                 Adicionando Navio                 \n");
                    printf("===================================================\n\n");
                    
                    int idNavio, quantidadeConteineres;

                    printf("  Digite a identificacao do Navio: ");
                    scanf("%d", &idNavio);

                    if (!procura_navio(idNavio, &navios)) {
                        printf("\n  [X] Navio ja registrado !\n");
                        getchar();
                        getchar();
                        break;
                    }

                    Navio* navioAux = criarNavio(idNavio);

                    printf("  Digite a quantidade de Conteineres armazenados (0 para nenhum): ");
                    scanf("%d", &quantidadeConteineres);

                    if (quantidadeConteineres > 0) {
                        printf("  [#] Gerando Conteineres\n");
                        for (int i = 0; i < quantidadeConteineres; i++) {
                            int idConteiner = gerarNumero(50, 1000);
                            
                            while (!procura_conteiner(idConteiner, &porto)) {
                                idConteiner = gerarNumero(50, 1000);
                            }
                            
                            if (!empilharContainer(navioAux, idConteiner)) {
                                printf("  [X] A pilha de containers esta cheia!\n");
                                break;
                            }
                        }
                        printf("  [+] Quantidade gerada com sucesso: %d\n", navioAux->quantidadeConteiner);
                    }

                    if (inserir(navioAux, &navios))
                        printf("  [+] Navio gerado com sucesso\n");
                    else
                        printf("  [X] Ocorreu um erro na hora de gerar o Navio\n");

                    getchar();
                    getchar();
                    break;
                
                case 4: // Remover Navio
                    exibir_tabela_navios(&navios);

                    printf("\n===================================================\n");
                    printf("                  Removendo Navios                 \n");
                    printf("===================================================\n\n");

                    if (!vazia(&navios)) {
                        int idNavio;

                        printf("  Digite Identificacao do Navio que deseja remover: ");
                        scanf("%d", &idNavio);

                        if (remover_navio(idNavio, &navios))
                            printf("\n  [+] Navio removido com Sucesso !\n");
                        else
                            printf("\n  [X] Navio inexistente !\n");
                    } else
                        printf("\n  [X] Sem navios registrados !\n");

                    getchar();
                    getchar();
                    break;

                default:
                    loop_navio = !loop_navio;
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
#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item da mochila
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;   // quantidade atual de itens cadastrados
    int opcao;

    do {
        printf("\n===== INVENTÁRIO DA MOCHILA =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            // ---------------------------
            // ADICIONAR ITEM
            // ---------------------------
            case 1:
                if (total >= MAX_ITENS) {
                    printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
                } else {
                    printf("Digite o nome do item: ");
                    scanf("%s", mochila[total].nome);

                    printf("Digite o tipo do item: ");
                    scanf("%s", mochila[total].tipo);

                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[total].quantidade);

                    total++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            // ---------------------------
            // REMOVER ITEM
            // ---------------------------
            case 2: {
                if (total == 0) {
                    printf("A mochila esta vazia! Nada para remover.\n");
                    break;
                }

                char nomeRemover[50];
                int encontrado = 0;

                printf("Digite o nome do item que deseja remover: ");
                scanf("%s", nomeRemover);

                for (int i = 0; i < total; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        // Desloca os itens para preencher o espaço
                        for (int j = i; j < total - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        total--;
                        encontrado = 1;
                        printf("Item removido com sucesso!\n");
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Item nao encontrado!\n");
                }
                break;
            }

            // ---------------------------
            // LISTAR ITENS
            // ---------------------------
            case 3:
                if (total == 0) {
                    printf("A mochila esta vazia.\n");
                } else {
                    printf("\n===== ITENS NA MOCHILA =====\n");
                    printf("%-15s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("----------------------------------------\n");

                    for (int i = 0; i < total; i++) {
                        printf("%-15s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

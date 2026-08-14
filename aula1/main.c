#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    char nome[100];
    float valor;
    int quantidade;
}
Produto;

void menu (int *opcao);
void cadastrarProduto (Produto *produto);
void exibirRelatorio (Produto *produto);

int main()
{
    Produto *estoque = NULL;
    int totalProdutos = 0;
    int opcao;

    do
    {
        menu (&opcao);

        switch (opcao)
        {
            case 1:
            {
                if (estoque == NULL)
                {
                    estoque = (Produto *) malloc(sizeof(Produto));
                }
                else
                {
                    estoque = (Produto *) realloc(estoque, (totalProdutos + 1) * sizeof(Produto));
                }
                
                if (estoque == NULL)
                {
                    printf("Erro ao alocar memoria!\n");
                    return 1;
                }

                printf("###### Cadastro de Produto ######\n");
                cadastrarProduto(&estoque[totalProdutos]);
                totalProdutos++;

                break;
            }

            case 2:
            {
                printf("###### RELATORIO DO ESTOQUE ######\n");
                for (int i = 0; i < totalProdutos; i++)
                {
                    exibirRelatorio(&estoque[i]);
                }
                break;
            }

            case 0:
            {
                free(estoque);
                printf("Saindo do programa\n");
                break;
            }

            default:
            {
                printf("Opcao invalida\n");
                break;
            }
        }
    }
    while(opcao != 0);

    return 0;
}

void menu(int *opcao)
{
    printf("###### CONTROLE DE ESTOQUE ######\n");
    printf("1 - Adicionar produto\n");
    printf("2 - Listar produtos\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

void cadastrarProduto(Produto *produto)
{
    printf("Nome: ");
    scanf(" %99[^\n]", produto->nome);

    printf("Valor: ");
    scanf("%f", &produto->valor);

    printf("Quantidade: ");
    scanf("%d", &produto->quantidade);
}

void exibirRelatorio(Produto *produto)
{
    if (produto == NULL) {
        printf("Nao ha produtos cadastrados\n");
        return;
    }

    float valorTotal = produto->valor * produto->quantidade;
    printf("Nome: %s; Valor: R$%.2f; Quantidade: %d; Valor total: R$%.2f\n", produto->nome, produto->valor, produto->quantidade, valorTotal);
}

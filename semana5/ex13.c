#include <stdio.h>
#include <stdlib.h>
#include "ex12/encadeada.h"

void removerIndice(Head *lista, int indice);

int main() {
    Head *lista = criaLista();
    if(lista == NULL) return 1;

    Dados produto1 = {1, "Arroz", 15.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    Dados produto4 = {4, "Agua", 2.00f};
    Dados produto5 = {5, "Carne", 25.00f};

    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);
    inserirFinal(lista, produto4);
    inserirFinal(lista, produto5);

    imprimirLista(lista);
    
    removerIndice(lista, 2);

    imprimirLista(lista);

    liberaLista(lista);

    return 0;
}

void removerIndice(Head *lista, int indice) {
    if(listaVazia(lista)) return;

    Nodo *atual = lista->pFirst;

    while(atual != NULL) {
        if(atual->info.cod == indice) {
            if(atual->ante == NULL) {
                lista->pFirst = atual->prox;
            } else {
                atual->ante->prox = atual->prox;
            }

            if(atual->prox != NULL) {
                atual->prox->ante = atual->ante;
            }
            
            free(atual);
            printf("Indice removido\n");
            return;
        }
        
        atual = atual->prox;
    }

    printf("Indice nao foi encontrado\n");
}

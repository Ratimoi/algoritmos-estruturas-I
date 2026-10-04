#include <stdlib.h>
#include <stdio.h>
#include "ex1/lista.h"

void removePares(Head *lista);

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

    removePares(lista);

    imprimirLista(lista);
    
    liberaLista(lista);

    return 0;
}

void removePares(Head *lista) {
    if(listaVazia(lista)) return;

    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *proximo = NULL;

    while(atual != NULL) {
        proximo = atual->prox;

        if(atual->info.cod % 2 == 0) {
            free(atual);

            if(anterior == NULL) {
                lista->pFirst = proximo;
            } else {
                anterior->prox = proximo;
            }
        } else {
            anterior = atual;
        }

        atual = proximo;
    }
}

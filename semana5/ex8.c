#include <stdio.h>
#include "ex1/lista.h"

void alternarLista(Head *lista1, Head *lista2);

int main() {
    Head *lista1 = criaLista();
    Head *lista2 = criaLista();
    if(lista1 == NULL || lista2 == NULL) return 1;

    Dados produto1 = {1, "Arroz", 15.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    Dados produto4 = {4, "Agua", 2.00f};
    Dados produto5 = {5, "Carne", 25.00f};

    inserirFinal(lista1, produto1);
    inserirFinal(lista2, produto2);
    inserirFinal(lista1, produto3);
    inserirFinal(lista2, produto4);
    inserirFinal(lista1, produto5);

    imprimirLista(lista1);
    imprimirLista(lista2);
    
    alternarLista(lista1, lista2);

    imprimirLista(lista1);
    imprimirLista(lista2);

    liberaLista(lista1);
    liberaLista(lista2);

    return 0;
}

void alternarLista(Head *lista1, Head *lista2) {
    if(listaVazia(lista1) || listaVazia(lista2)) return;

    Nodo *atual1 = lista1->pFirst;
    Nodo *atual2 = lista2->pFirst;
    Nodo *prox1;
    Nodo *prox2;
    
    while(atual1 != NULL && atual2 != NULL) {
        prox1 = atual1->prox;
        prox2 = atual2->prox;

        atual1->prox = atual2;
        atual2->prox = (prox1 != NULL) ? prox1 : prox2;

        atual1 = prox1;
        atual2 = prox2;
    }

    lista2->pFirst = NULL;
}

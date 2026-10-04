#include <stdio.h>
#include "ex1/lista.h"

void incorporeLista(Head *lista1, Head *lista2);

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
    inserirFinal(lista1, produto2);
    inserirFinal(lista1, produto3);
    inserirFinal(lista2, produto4);
    inserirFinal(lista2, produto5);

    imprimirLista(lista1);
    imprimirLista(lista2);
    
    incorporeLista(lista1, lista2);
    
    imprimirLista(lista1);
    imprimirLista(lista2);

    liberaLista(lista1);
    liberaLista(lista2);

    return 0;
}

void incorporeLista(Head *lista1, Head *lista2) {
    if(listaVazia(lista1) || listaVazia(lista2)) return;

    Nodo *temp = lista1->pFirst;

    while(temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = lista2->pFirst;
    lista2->pFirst = NULL;
}

#include <stdio.h>
#include "ex1/lista.h"

void separaPares(Head *lista, Head *pares, Head *impares);

int main() {
    Head *lista = criaLista();
    Head *pares = criaLista();
    Head *impares = criaLista();
    if(lista == NULL || pares == NULL || impares == NULL) return 1;

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
    imprimirLista(pares);
    imprimirLista(impares);

    separaPares(lista, pares, impares);

    imprimirLista(lista);
    imprimirLista(pares);
    imprimirLista(impares);
    
    liberaLista(lista);
    liberaLista(pares);
    liberaLista(impares);

    return 0;
}

void separaPares(Head *lista, Head *pares, Head *impares) {
    if(listaVazia(lista)) return;

    Nodo *atual = lista->pFirst;

    do {
        (atual->info.cod % 2 == 0) ? inserirFinal(pares, atual->info) : inserirFinal(impares, atual->info);
        atual = atual->prox;
    } while(atual->prox != NULL);
}

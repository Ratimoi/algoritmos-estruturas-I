#include <stdio.h>
#include <stdlib.h>
#include "ex1/lista.h"

Head *copiaLista(Head *lista);

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

    Head *copia = copiaLista(lista);

    imprimirLista(lista);
    imprimirLista(copia);
    
    liberaLista(lista);
    liberaLista(copia);

    return 0;
}

Head *copiaLista(Head *lista) {
    if(listaVazia(lista)) return NULL;

    Head *copia = (Head *)malloc(sizeof(Head));
    if(copia == NULL) {
        printf("Falha na memoria\n");
        return NULL;
    }

    Nodo *atual = lista->pFirst;
    Nodo *ultimo = NULL;
    
    while(atual != NULL) {
        Nodo *novo = malloc(sizeof(Nodo));

        novo->info = atual->info;
        novo->prox = NULL;

        if (ultimo == NULL) {
            copia->pFirst = novo;
        } else {
            ultimo->prox = novo;
        }

        ultimo = novo;
        atual = atual->prox;
    }

    return copia;
}

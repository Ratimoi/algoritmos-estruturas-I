#include <stdio.h>
#include <stdlib.h>
#include "ex1/lista.h"

void inverteOrdem(Head *lista);

int main() {
    Head *lista = criaLista();
    if(lista == NULL) return 1;

    Dados produto1 = {1, "Arroz", 25.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    
    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);

    imprimirLista(lista);
    
    inverteOrdem(lista);
    
    imprimirLista(lista);

    liberaLista(lista);
    
    return 0;
}

void inverteOrdem(Head *lista) {
    if (listaVazia(lista)) return;

    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *proximo;

    while(atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->pFirst = anterior;
}

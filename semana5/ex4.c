#include <stdio.h>
#include <stdlib.h>
#include "ex1/lista.h"

void removerCodigo(Head *lista, int codigo);

int main() {
    Head *lista = criaLista();
    if(lista == NULL) return 1;

    Dados produto1 = {1, "Arroz", 25.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    Dados produto4 = {2, "Feijao", 8.75f};
    Dados produto5 = {3, "Macarrao", 5.00f};
    Dados produto6 = {2, "Feijao", 8.75f};
    Dados produto7 = {1, "Arroz", 25.50f};
    
    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);
    inserirFinal(lista, produto4);
    inserirFinal(lista, produto5);
    inserirFinal(lista, produto6);
    inserirFinal(lista, produto7);

    imprimirLista(lista);
    
    removerCodigo(lista, 2);
    
    imprimirLista(lista);

    liberaLista(lista);
    
    return 0;
}

void removerCodigo(Head *lista, int codigo) {
    if (listaVazia(lista)) return;

    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;

    while (atual != NULL) {
        if (atual->info.cod == codigo) {
            Nodo *removido = atual;

            if (anterior == NULL) {
                lista->pFirst = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            atual = atual->prox;
            free(removido);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

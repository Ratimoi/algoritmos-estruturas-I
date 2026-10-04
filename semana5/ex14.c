#include <stdlib.h>
#include <stdio.h>
#include "ex12/encadeada.h"

void verificaPalindrome(Head *lista);

int main() {
    Head *lista = criaLista();
    if(lista == NULL) return 1;

    Dados produto1 = {1, "Arroz", 15.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    Dados produto4 = {2, "Agua", 2.00f};
    Dados produto5 = {1, "Carne", 25.00f};

    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);
    inserirFinal(lista, produto4);
    inserirFinal(lista, produto5);

    imprimirLista(lista);

    verificaPalindrome(lista);

    liberaLista(lista);

    return 0;
}

void verificaPalindrome(Head *lista) {
    if(listaVazia(lista)) return;

    Nodo *dir = lista->pFirst;
    Nodo *esq = lista->pFirst;
    int count = 0;

    while(dir->prox != NULL) {
        dir = dir->prox;
        count += 1;
    }

    for(int i = 0; i < count; i++) {
        if(esq->info.cod != dir->info.cod) {
            printf("Lista nao e palindrome\n");
            return;
        }

        esq = esq->prox;
        dir = dir->ante;
    }

    printf("Lista e palindrome\n");
}

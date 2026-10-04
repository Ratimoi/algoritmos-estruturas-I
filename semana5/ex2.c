#include <stdbool.h>
#include <stdio.h>
#include "ex1/lista.h"

int quantidadeElementos(Head *lista);

int main() {
    Head *lista = criaLista();
    if (lista == NULL) {
        return 1;
    }

    Dados produto1 = {1, "Arroz", 25.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};

    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);

    int quantidade = quantidadeElementos(lista);    

    printf("Quantidade de elementos: %d", quantidade);

    liberaLista(lista);

    return 0;
}

int quantidadeElementos(Head *lista) {
    if(listaVazia(lista)) return 0;

    Nodo *temp = lista->pFirst;
    int contador = 1;
    
    while(temp->prox != NULL) {
        contador++;
        temp = temp->prox;
    }

    return contador;
}

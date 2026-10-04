#include <stdio.h>
#include "ex1/lista.h"

void inverteOrdemN(Head *lista, int valor);
int quantidadeElementos(Head *lista);

int main() {
    Head *lista = criaLista();
    if(lista == NULL) return 1;

    Dados produto1 = {1, "Arroz", 25.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    Dados produto4 = {4, "Agua", 5.00f};
    
    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);
    inserirFinal(lista, produto4);

    imprimirLista(lista);
    
    inverteOrdemN(lista, 3);
    
    imprimirLista(lista);

    liberaLista(lista);
    
    return 0;
}

void inverteOrdemN(Head *lista, int valor) {
    if (listaVazia(lista)) return;

    if(valor <= 0 || valor > quantidadeElementos(lista)) {
        printf("Insira um valor valido\n");
        return;
    }

    Nodo *inicio = lista->pFirst;
    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *proximo;

    for(int i = 0; i < valor; i++) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    inicio->prox = atual;
    lista->pFirst = anterior;
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

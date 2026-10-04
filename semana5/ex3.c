#include <stdio.h>
#include "ex1/lista.h"

int comparaMaiorValor(Head *lista, int valor);

int main() {
    Head *lista = criaLista();
    if(lista == NULL) return 1;

    Dados produto1 = {1, "Arroz", 25.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};

    inserirFinal(lista, produto1);
    inserirFinal(lista, produto2);
    inserirFinal(lista, produto3);

    int quantidade = comparaMaiorValor(lista, 7);

    printf("Quantidade de elementos: %d", quantidade);

    liberaLista(lista);
    
    return 0;
}

int comparaMaiorValor(Head *lista, int valor) {
    if(listaVazia(lista)) return 0;

    Nodo *temp = lista->pFirst;
    int contador = 0;
    
    while(temp != NULL) {
        if(temp->info.preco > valor) {
            contador++;
        }

        temp = temp->prox;
    }

    return contador;
}

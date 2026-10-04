#include <stdbool.h>
#include <stdio.h>
#include "lista.h"

int main(void) {
    Head *lista = criaLista();
    if (lista == NULL) {
        return 1;
    }

    Dados produto1 = {1, "Arroz", 25.50f};
    Dados produto2 = {2, "Feijao", 8.75f};
    Dados produto3 = {3, "Macarrao", 5.00f};
    Dados resultado;
    bool encontrado;

    inserirInicio(lista, produto1);
    inserirFinal(lista, produto2);
    inserirInicio(lista, produto3);

    printf("Lista apos insercoes:\n");
    imprimirLista(lista);

    encontrado = buscar(lista, 2, &resultado);
    if (encontrado) {
        printf("Produto buscado: %s - R$ %.2f\n", resultado.nome, resultado.preco);
    }

    removerInicio(lista);
    removerFinal(lista);

    printf("Lista apos remocoes:\n");
    imprimirLista(lista);

    liberaLista(lista);
    return 0;
}

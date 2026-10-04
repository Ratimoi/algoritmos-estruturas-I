#include <stdlib.h>
#include <stdio.h>
#include "encadeada.h"

Head *criaLista() {
    Head *lista = (Head *)malloc(sizeof(Head));
    if (lista == NULL) {
        printf("Falha na memoria\n");
        return NULL;
    }
    
    lista->pFirst = NULL;
    return lista;
}

int buscar(Head *lista, int cod, Dados *resultado) {
    if(lista == NULL || resultado == NULL) {
        printf("Lista vazia ou memoria de resultado invalido\n");
        return 0;
    }

    Nodo *temp = lista->pFirst;

    while (temp != NULL) {
        if(temp->info.cod == cod) {
            printf("Codigo encontrado\n");
            *resultado = temp->info;
            return 1;
        }

        temp = temp->prox;
    }

    printf("Lista nao encontrada\n");
    return 0;
}

int listaVazia(Head *lista) {
    return lista == NULL || lista->pFirst == NULL;
}

int removerInicio(Head *lista) {
    if(listaVazia(lista)) return 0;

    if(lista->pFirst->prox == NULL) {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1;
    }

    Nodo *temp = lista->pFirst;
    lista->pFirst = lista->pFirst->prox;
    lista->pFirst->ante = NULL;
    
    free(temp);
    
    return 1;
}

int removerFinal(Head *lista) {
    if(listaVazia(lista)) return 0;
    
    if(lista->pFirst->prox == NULL) {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1;
    }

    Nodo *ultimo = lista->pFirst;

    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    ultimo->ante->prox = NULL;
    free(ultimo);

    return 1;
}

void inserirInicio(Head *lista, Dados dado) {
    if(lista == NULL) return;
    
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    
    if(novo == NULL) {
        printf("Falha na memoria\n");
        return;
    }

    novo->info = dado;
    novo->prox = lista->pFirst;
    novo->ante = NULL;

    if (lista->pFirst != NULL) {
        lista->pFirst->ante = novo;
    }

    lista->pFirst = novo;
}

void inserirFinal(Head *lista, Dados dado) {
    if(lista == NULL) return;

    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    
    if(novo == NULL) {
        printf("Falha na memoria\n");
        return;
    }

    novo->info = dado;
    novo->prox = NULL;
    novo->ante = NULL;

    if(lista->pFirst == NULL) {
        lista->pFirst = novo;
        return;
    }

    Nodo *ultimo = lista->pFirst;

    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    novo->ante = ultimo;
    ultimo->prox = novo;
}

void imprimirLista(Head *lista) {
    if(listaVazia(lista)) {
        printf("Lista vazia\n");
        printf("\n");
        return;
    }
    
    Nodo *temp = lista->pFirst;
    
    printf("=== Lista de Itens ===\n");
    do {
        printf("Codigo: %d\n", temp->info.cod);
        printf("Nome: %s\n", temp->info.nome);
        printf("Preco: %f\n", temp->info.preco);
        printf("\n");

        temp = temp->prox;
    } while (temp != NULL);
}

void liberaLista(Head *lista) {
    if(listaVazia(lista)) {
        free(lista);
        return;
    }

    Nodo *temp;
    
    while(lista->pFirst != NULL) {
        temp = lista->pFirst;
        lista->pFirst = lista->pFirst->prox;
        free(temp);
    }

    free(lista);
}

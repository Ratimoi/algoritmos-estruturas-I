#ifndef LISTA_H
#define LISTA_H

typedef struct Dados {
	int cod;
	char nome[10];
	float preco;
} Dados;

typedef struct Nodo {
    Dados info;
	struct Nodo *prox;
} Nodo;

typedef struct Head {
    Nodo *pFirst;
} Head;

Head *criaLista();

int buscar(Head *lista, int cod, Dados *resultado);
int listaVazia(Head *lista);
int removerInicio(Head *lista);
int removerFinal(Head *lista);

void inserirInicio(Head *lista, Dados dado);
void inserirFinal(Head *lista, Dados dado);
void imprimirLista(Head *lista);
void liberaLista(Head *lista);

#endif

#include <stdio.h>
#include <stdlib.h>

int *inserir(int *v, int *n, int valor);
int *lerVetorInt(int *tamanho);
void imprimeVetor(int *v, int *n);

int main() {
    int tamanho;
    int *vetor = lerVetorInt(&tamanho);

    int x = 0;
    printf("Insira um valor: ");
    scanf("%d", &x);

    vetor = inserir(vetor, &tamanho, x);

    printf("Vetor: ");
    imprimeVetor(vetor, &tamanho);
    printf("\n");

    free(vetor);

    return 0;
}

int *inserir(int *v, int *n, int valor) {
    int *novoVetor = (int *)realloc(v, sizeof(int) * (*n + 1));
    if(!novoVetor) {
        return NULL;
    }
    
    v = novoVetor;
    *n += 1;
    v[(*n) - 1] = valor;

    return v;
}

int *lerVetorInt(int *tamanho) {
    printf("Insira o tamanho do vetor: ");
    if (scanf("%d", tamanho) != 1 || *tamanho <= 0) {
        return NULL;
    }

    int *vetor = malloc(sizeof(int) * (*tamanho));
    if (vetor == NULL) {
        return NULL;
    }

    for (int i = 0; i < *tamanho; i++) {
        printf("Insira a %d posicao: ", i + 1);
        if (scanf("%d", &vetor[i]) != 1) {
            free(vetor);
            return NULL;
        }
    }

    printf("\n");

    return vetor;
}

void imprimeVetor(int *v, int *n) {
    for(int i = 0; i < (*n); i++) {
        printf("%d ", v[i]);
    }
}

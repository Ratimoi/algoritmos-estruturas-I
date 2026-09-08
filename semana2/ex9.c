#include <stdio.h>
#include <stdlib.h>

int *lerVetorInt(int *tamanho);
int *copia_vetor(int *v, int n);

int main() {
    int *tamanho;
    int *vetor = lerVetorInt(tamanho);

    int *novoVetor = copia_vetor(vetor, *tamanho);

    printf("Vetor: ");
    for(int i = 0; i < *tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\n");

    printf("Novo vetor: ");
    for(int i = 0; i < *tamanho; i++) {
        printf("%d ", novoVetor[i]);
    }

    free(vetor);
    free(novoVetor);

    return 0;
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
        scanf("%d", &vetor[i]);
    }

    return vetor;
}

int *copia_vetor(int *v, int n) {
    int *vetor = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        vetor[i] = *&v[i];
    }

    return vetor;
}

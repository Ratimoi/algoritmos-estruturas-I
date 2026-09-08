#include <stdio.h>
#include <stdlib.h>

int remover(int **v, int *n, int posicao);
int *lerVetorInt(int *tamanho);
void imprimeVetor(int *v, int n);

int main() {
    int tamanho;
    int *vetor = lerVetorInt(&tamanho);

    printf("Vetor: ");
    imprimeVetor(vetor, tamanho);
    printf("\n");
    
    int posicao;
    if(tamanho > 1) {
        printf("Insira a posicao para remover: ");
        scanf("%d", &posicao);
    } else {
        posicao = 0;
    }
    
    if(remover(&vetor, &tamanho, posicao)) {
        printf("Inteiro removido com sucesso\n");
        printf("Vetor: ");
        imprimeVetor(vetor, tamanho);
        printf("\n");
    } else {
        printf("Erro ao remover vetor\n");
    }

    free(vetor);

    return 0;
}

int remover(int **v, int *n, int posicao) {
    if((*n) <= 1) {
        free(*v);
        *v = NULL;
        *n = 0;
        return 1;
    }

    if(posicao < 0 || posicao >= *n) return 0;

    for(int i = posicao; i < (*n) - 1; i++) {
        (*v)[i] = (*v)[i + 1];
    }

    *n -= 1;
    int *novo = (int *)realloc(*v, sizeof(int) * (*n));
    if(!novo && (*n) > 0) return 0;

    *v = novo;

    return 1;
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

void imprimeVetor(int *v, int n) {
    if(n > 0) {
        for(int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
    } else {
        printf("Vetor vazio\n");
    }
}

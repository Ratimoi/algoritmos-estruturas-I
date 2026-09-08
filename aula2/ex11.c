#include <stdio.h>
#include <stdlib.h>

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3);
int *lerVetorInt(int *tamanho);

int main() {
    int tamanho1;
    int *vetor1 = lerVetorInt(&tamanho1);

    int tamanho2;
    int *vetor2 = lerVetorInt(&tamanho2);
    
    int tamanho3;
    int *vetor3 = concatenar(vetor1, tamanho1, vetor2, tamanho2, &tamanho3);

    printf("Vetor concatenado: ");
    for(int i = 0; i < tamanho3; i++) {
        printf("%d ", vetor3[i]);
    }
    printf("\n");
    
    free(vetor1);
    free(vetor2);
    free(vetor3);

    return 0;
}

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3) {
    *n3 = n1 + n2;

    int *vetor = (int *)malloc(sizeof(int) * (*n3));
    if(!vetor) {
        return NULL;
    }

    for(int i = 0; i < n1; i++) {
        vetor[i] = v1[i];
    }
    
    for(int i = 0; i < n2; i++) {
        vetor[(*n3) - n1 - 1 + i] = v2[i];
    }

    return vetor;
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

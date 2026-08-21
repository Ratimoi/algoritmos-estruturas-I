#include <stdio.h>
#include <stdlib.h>

int *lerVetorInt(int *tamanho);
void min_max(int *v, int n, int *min, int *max);

int main() {
    int tamanho = 0;
    int *vetor = lerVetorInt(&tamanho);
    if (vetor == NULL) {
        return 1;
    }

    int max, min;
    min_max(vetor, tamanho, &min, &max);

    printf("Vetor: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    printf("Quantidade de valores: %d\n", tamanho);
    printf("Maior valor: %d\n", max);
    printf("Menor valor: %d\n", min);

    free(vetor);
}

int *lerVetorInt(int *tamanho) {
    int *vetor = (int *)malloc(sizeof(int));
    if (vetor == NULL) {
        return NULL;
    }
    
    int numero;
    
    while (1) {
        printf("Insira um numero ou -1 para sair: ");
        if (scanf("%d", &numero) != 1) {
            free(vetor);
            return NULL;
        }
        
        if (numero == -1) {
            break;
        }
        
        (*tamanho)++;
        vetor = (int *)realloc(vetor, sizeof(int) * (*tamanho));
        if (vetor == NULL) {
            return NULL;
        }

        vetor[(*tamanho) - 1] = numero;
    }

    return vetor;
}

void min_max(int *v, int n, int *min, int *max)  {
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < n; i++) {
        if (*max < v[i]) {
            *max = v[i];
        } else if (*min > v[i]) {
            *min = v[i];
        }
    }
}
